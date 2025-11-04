#include <iostream>

// stb_wrapper.cpp

// A. 서로 독립적인 모듈
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_PERLIN_IMPLEMENTATION
#include "stb_perlin.h"

#define STB_LEAKCHECK_IMPLEMENTATION
#include "stb_leakcheck.h"

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

// B. rect_pack 과 truetype 은 함께 포함해야 함 (truetype 내부에서 사용)
#define STB_RECT_PACK_IMPLEMENTATION
#include "stb_rect_pack.h"

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

// C. voxel_render 는 반드시 별도 설정 매크로 필요
#define STBVOX_CONFIG_MODE STBVOX_MODE_LERP
#define STB_VOXEL_RENDER_IMPLEMENTATION
#include "stb_voxel_render.h"
