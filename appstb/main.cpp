#include <iostream>
#include <string>
#include <vector>
#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_truetype.h"
#include "stb_perlin.h"
#include "stb_vorbis.c"
#include "stb_leakcheck.h"
#include "stb_ds.h"

void example_image_load() {
    int w, h, c;
    unsigned char* data = stbi_load("test.png", &w, &h, &c, 0);
    if (data) {
        std::cout << "Loaded image: " << w << "x" << h << " (" << c << " channels)\n";
        stbi_image_free(data);
    } else {
        std::cout << "Failed: " << stbi_failure_reason() << "\n";
    }
}

void example_image_write() {
    const int w = 64, h = 64;
    std::vector<unsigned char> img(w * h * 3);
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x) {
            img[(y*w+x)*3+0] = x * 4;
            img[(y*w+x)*3+1] = y * 4;
            img[(y*w+x)*3+2] = 128;
        }
    stbi_write_png("out.png", w, h, 3, img.data(), w * 3);
    std::cout << "Saved out.png\n";
}

void example_truetype() {
    FILE* f = fopen("arial.ttf", "rb");
    if (!f) { std::cout << "arial.ttf not found.\n"; return; }
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);
    std::vector<unsigned char> buf(size);
    fread(buf.data(), 1, size, f);
    fclose(f);

    stbtt_fontinfo font;
    stbtt_InitFont(&font, buf.data(), stbtt_GetFontOffsetForIndex(buf.data(), 0));

    int w, h;
    unsigned char* bmp = stbtt_GetCodepointBitmap(&font, 0, stbtt_ScaleForPixelHeight(&font, 32), 'A', &w, &h, 0, 0);
    std::cout << "Generated bitmap for 'A': " << w << "x" << h << "\n";
    stbtt_FreeBitmap(bmp, nullptr);
}

void example_perlin() {
    for (int i = 0; i < 5; ++i)
        std::cout << "Perlin(" << i << ") = " << stb_perlin_noise3(i, i * 0.3f, 0, 0, 0, 0) << "\n";
}

void example_vorbis() {
    int ch, sr;
    short* out;
    int n = stb_vorbis_decode_filename("test.ogg", &ch, &sr, &out);
    if (n < 0) std::cout << "Failed to decode OGG.\n";
    else std::cout << "Decoded " << n << " samples (" << ch << "ch, " << sr << "Hz)\n";
    free(out);
}

void example_ds()
{
    // 반드시 'val'로 선언해야 합니다.
    struct { const char* key; int val; } *map = nullptr;

    hmput(map, "apple", 10);
    hmput(map, "banana", 20);
    hmput(map, "cherry", 30);

    std::cout << "apple = " << hmget(map, "apple") << "\n";
    std::cout << "banana = " << hmget(map, "banana") << "\n";
    std::cout << "cherry = " << hmget(map, "cherry") << "\n";

    hmfree(map);
}

int main(int argc, char** argv) {
    if (argc < 3 || std::string(argv[1]) != "--example") {
        std::cout << "Usage: appstb --example <name>\n"
                  << "Examples:\n"
                  << "  image_load\n"
                  << "  image_write\n"
                  << "  truetype\n"
                  << "  perlin\n"
                  << "  vorbis\n"
                  << "  ds\n";
        return 0;
    }

    std::string name = argv[2];
    if (name == "image_load") example_image_load();
    else if (name == "image_write") example_image_write();
    else if (name == "truetype") example_truetype();
    else if (name == "perlin") example_perlin();
    else if (name == "vorbis") example_vorbis();
    else if (name == "ds") example_ds();
    else std::cout << "Unknown example: " << name << "\n";

    return 0;
}
