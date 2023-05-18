#pragma once
#include <cstdint>

namespace ExEdit {
    struct ExdataUse {
        enum class Type : int16_t {
            Padding = 0,
            Number = 1,
            String = 2,
            Binary = 3
        };

        Type type;
        int16_t size;
        const char* name;
    };

    namespace Exdata {
        struct ExdataColor {
            unsigned char b, g, r;
            unsigned char padding;
        };

        struct ExdataColorOpt {
            unsigned char b, g, r;
            unsigned char no_color;
        };

        struct ExdataColorYC {
            int16_t y, cb, cr;
            int16_t padding;
        };

        struct ExdataColorYCOpt {
            int16_t y, cb, cr;
            int16_t status;
        };

        struct ExdataBase {};

        struct efMovieFile : ExdataBase {
            char file[260];
            int32_t i1;
            int32_t i2;
            int32_t frame_n;
            int32_t video_rate;
            int32_t video_scale;
            int32_t i3;
        };

        struct efImageFile : ExdataBase {
            int32_t unknown;
            char file[256];
        };

        struct efAudioFile : ExdataBase {
            char file[260];
            int32_t i1;
            int32_t i2;
            int32_t frame_n;
            int32_t i4;
            int32_t i5;
        };

        struct efText : ExdataBase {
            unsigned char type;
            unsigned char autoadjust;
            unsigned char soft;
            unsigned char monospace;
            signed char align;
            signed char spacing_x;
            signed char spacing_y;
            unsigned char precision;
            ExdataColor color;
            ExdataColor color2;
            char font[32];
            wchar_t text[1024];
        };

        struct efFigure : ExdataBase {
            int32_t type;
            ExdataColor color;
            unsigned char padding;
            char name[256];
        };

        struct efWaveForm : ExdataBase {
            char file[260];
            int32_t i1;
            int32_t i2;
            int32_t frame_n;
            int32_t i4;
            int32_t i5;
            int16_t type;
            int16_t mode;
            int16_t res_W;
            int16_t res_h;
            ExdataColor color;
            int32_t sample_n;
            char mirror;
            char padding[3];
        };

        struct efScene : ExdataBase {
            int32_t scene;
        };

        struct efSceneAudio : ExdataBase {
            int32_t scene;
        };

        struct efNormalDraw : ExdataBase {
            int32_t blend;
        };

        struct efExtendedDraw : ExdataBase {
            int32_t blend;
        };

        struct efParticle : ExdataBase {
            int32_t blend;
        };

        struct efSceneChange : ExdataBase {
            int16_t type;
            int16_t filter;
            char name[256];
            char param[256];
        };

        struct efLightEmission : ExdataBase {
            ExdataColorOpt color;
        };

        struct efFlash : ExdataBase {
            ExdataColorOpt color;
            int32_t mode;
        };

        struct efGlow : ExdataBase {
            ExdataColorOpt color;
            int32_t type;
        };

        struct efChromakey : ExdataBase {
            ExdataColorYC color;
            int32_t status;
        };

        struct efColorKey : ExdataBase {
            ExdataColorYC color;
            int32_t status;
        };

        struct efLuminanskey : ExdataBase {
            int32_t type;
        };

        struct efLight : ExdataBase {
            ExdataColor color;
        };

        struct efShadow : ExdataBase {
            ExdataColor color;
            char file[256];
        };

        struct efBorder : ExdataBase {
            ExdataColor color;
            char file[256];
        };

        struct efExtractEdge : ExdataBase {
            ExdataColor color;
        };

        struct efWipe : ExdataBase {
            int32_t type;
            char name[256];
        };

        struct efMask : ExdataBase {
            int32_t type;
            char name[256];
            int32_t mode;
        };

        struct efMirror : ExdataBase {
            int32_t type;
            char name[256];
        };

        struct efRipple : ExdataBase {
            int32_t num;
            int32_t interval;
            int32_t add;
        };

        struct efDisplacementMap : ExdataBase {
            int32_t type;
            char name[256];
            int32_t mode;
            int32_t calc;
        };

        struct efNoise : ExdataBase {
            int32_t type;
            int32_t mode;
            int32_t seed;
        };
        
        struct efColorDrift : ExdataBase {
            int32_t type;
        };

        struct efMonochromatic : ExdataBase {
            ExdataColor color;
        };

        struct efGradation : ExdataBase {
            int32_t blend;
            ExdataColorOpt color;
            ExdataColorOpt color2;
            int32_t type;
        };

        struct efSpecialColorConversion : ExdataBase {
            ExdataColorYCOpt color_yc;
            ExdataColorYCOpt color_yc2;
        };

        struct efAnimationEffect : ExdataBase {
            int16_t type;
            int16_t filter;
            char name[256];
            char param[256];
        };

        struct efScriptControl : ExdataBase {
            wchar_t text[1024];
        };

        struct efMovieSynthesis : ExdataBase {
            char file[260];
            int32_t i1;
            int32_t i2;
            int32_t frame_n;
            int32_t video_rate;
            int32_t video_scale;
            int32_t i3;
            int32_t mode;
        };

        struct efImageSynthesis : ExdataBase {
            int32_t mode;
            char file[256];
        };

        struct efDeinterlacing : ExdataBase {
            int32_t type;
        };

        struct efPortionFilter : ExdataBase {
            int32_t type;
            char name[256];
        };

        struct efTimeControl : ExdataBase {
            int32_t range;
            int32_t unknown[4];
        };

        struct efGroupControl : ExdataBase {
            int32_t range;
            int32_t unknown[4];
        };

        struct efCameraControl : ExdataBase {
            int32_t range;
            int32_t unknown[4];
        };

        struct efCameraControlExDraw : ExdataBase {
            int32_t target;
        };
    }
    
    namespace ExdataUseConst {
        inline const ExdataUse efMovieFile[] {
            { .type = ExdataUse::Type::String, .size = 260, .name = "file" },
            { .type = ExdataUse::Type::Padding, .size = 24, .name = nullptr },
        };

        inline const ExdataUse efImageFile[] {
            { .type = ExdataUse::Type::Padding, .size = 4, .name = nullptr },
            { .type = ExdataUse::Type::String, .size = 256, .name = "file" },
        };

        inline const ExdataUse efAudioFile[] {
            { .type = ExdataUse::Type::String, .size = 260, .name = "file" },
            { .type = ExdataUse::Type::Padding, .size = 20, .name = nullptr },
        };

        inline const ExdataUse efText[] {
            { .type = ExdataUse::Type::Number, .size = 1, .name = "type" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "autoadjust" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "soft" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "monospace" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "align" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "spacing_x" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "spacing_y" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "precision" },
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr },
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color2" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr },
            { .type = ExdataUse::Type::String, .size = 32, .name = "font" },
            { .type = ExdataUse::Type::Binary, .size = 2048, .name = "text" },
        };

        inline const ExdataUse efFigure[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr },
            { .type = ExdataUse::Type::String, .size = 256, .name = "name" },
        };

        inline const ExdataUse efWaveForm[] {
            { .type = ExdataUse::Type::String, .size = 260, .name = "file" },
            { .type = ExdataUse::Type::Padding, .size = 20, .name = nullptr },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "type" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "mode" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "res_w" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "res_h" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "pad_w" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "pad_h" },
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "sample_n" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "mirror" },
            { .type = ExdataUse::Type::Padding, .size = 3, .name = nullptr },
        };

        inline const ExdataUse efScene[]{
            { .type = ExdataUse::Type::Number, .size = 4, .name = "scene" },
        };

        inline const ExdataUse efSceneAudio[]{
            { .type = ExdataUse::Type::Number, .size = 4, .name = "scene" },
        };

        inline const ExdataUse efNormalDraw[]{
            { .type = ExdataUse::Type::Number, .size = 4, .name = "blend" },
        };

        inline const ExdataUse efExtendedDraw[]{
            { .type = ExdataUse::Type::Number, .size = 4, .name = "blend" },
        };

        inline const ExdataUse efParticle[]{
            { .type = ExdataUse::Type::Number, .size = 4, .name = "blend" },
        };

        inline const ExdataUse efSceneChange[]{
            { .type = ExdataUse::Type::Number, .size = 2, .name = "type" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "filter" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "name" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "param" },
        };

        inline const ExdataUse efLightEmission[]{
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "no_color" },
        };

        inline const ExdataUse efFlash[]{
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "no_color" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "mode" },
        };

        inline const ExdataUse efGlow[]{
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "no_color" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
        };

        inline const ExdataUse efChromakey[]{
            { .type = ExdataUse::Type::Binary, .size = 6, .name = "color_yc" },
            { .type = ExdataUse::Type::Padding, .size = 2, .name = nullptr },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "status" },
        };

        inline const ExdataUse efColorKey[]{
            { .type = ExdataUse::Type::Binary, .size = 6, .name = "color_yc" },
            { .type = ExdataUse::Type::Padding, .size = 2, .name = nullptr },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "status" },
        };

        inline const ExdataUse efLuminanskey[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" }
        };

        inline const ExdataUse efLight[] {
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr }
        };

        inline const ExdataUse efShadow[] {
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr },
            { .type = ExdataUse::Type::String, .size = 256, .name = "file" },
        };

        inline const ExdataUse efBorder[] {
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr },
            { .type = ExdataUse::Type::String, .size = 256, .name = "file" },
        };

        inline const ExdataUse efExtractEdge[] {
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Padding, .size = 1, .name = nullptr }
        };
    

        inline const ExdataUse efWipe[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "name" }
        };

        inline const ExdataUse efMask[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "name" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "mode" }
        };
    
        inline const ExdataUse efMirror[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" }
        };

        inline const ExdataUse efRipple[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "num" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "interval" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "add" }
        };

        inline const ExdataUse efDisplacementMap[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "name" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "mode" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "calc" }
        };

        inline const ExdataUse efNoise[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "mode" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "seed" },
            { .type = ExdataUse::Type::Padding, .size = 4, .name = nullptr }
        };
    
        inline const ExdataUse efColorDrift[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
        };

        inline const ExdataUse efGradation[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "blend" },
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "no_color" },
            { .type = ExdataUse::Type::Binary, .size = 3, .name = "color2" },
            { .type = ExdataUse::Type::Number, .size = 1, .name = "no_color2" },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
        };

        inline const ExdataUse efSpecialColorConversion[] {
            { .type = ExdataUse::Type::Binary, .size = 6, .name = "color" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "status" },
            { .type = ExdataUse::Type::Binary, .size = 6, .name = "color2" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "status2" },
        };

        inline const ExdataUse efAnimationEffect[] {
            { .type = ExdataUse::Type::Number, .size = 2, .name = "type" },
            { .type = ExdataUse::Type::Number, .size = 2, .name = "filter" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "name" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "param" },
        };

        inline const auto& efCustomObject = efAnimationEffect;

        inline const ExdataUse efScriptControl[] {
            { .type = ExdataUse::Type::Binary, .size = 2048, .name = "text" }
        };

        inline const ExdataUse efMovieSynthesis[] {
            { .type = ExdataUse::Type::String, .size = 260, .name = "file" },
            { .type = ExdataUse::Type::Padding, .size = 24, .name = nullptr },
            { .type = ExdataUse::Type::Number, .size = 4, .name = "mode" }
        };

        inline const ExdataUse efImageSynthesis[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "mode" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "file" },
        };
        
        inline const ExdataUse efDeinterlacing[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" }
        };

        inline const ExdataUse efPortionFilter[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "type" },
            { .type = ExdataUse::Type::String, .size = 256, .name = "name" },
        };

        inline const ExdataUse efTimeControl[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "range" },
            { .type = ExdataUse::Type::Padding, .size = 16, .name = nullptr },
        };
        
        inline const ExdataUse efGroupControl[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "range" },
            { .type = ExdataUse::Type::Padding, .size = 16, .name = nullptr },
        };

        inline const ExdataUse efCameraControl[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "range" },
            { .type = ExdataUse::Type::Padding, .size = 16, .name = nullptr },
        };

        inline const ExdataUse efCameraControlExDraw[] {
            { .type = ExdataUse::Type::Number, .size = 4, .name = "target" },
        };
    }

} // namespace ExEdit
