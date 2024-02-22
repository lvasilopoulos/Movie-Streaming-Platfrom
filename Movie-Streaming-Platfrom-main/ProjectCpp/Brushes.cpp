#include "FilmBrowserBrushes.h"

/// <summary>
/// Returns the black brush
/// </summary>
graphics::Brush FilmBrowserBrushes::black() {
    graphics::Brush brush = { 0 };
    
    return brush;
}

/// <summary>
/// Returns the white brush
/// </summary>
graphics::Brush FilmBrowserBrushes::white() {
    graphics::Brush brush;    

    return brush;
}

/// <summary>
/// Returns the opaque brush (used for images)
/// </summary>

graphics::Brush FilmBrowserBrushes::opaque() {
    graphics::Brush brush;
    brush.fill_color[0] = 1.0f;
    brush.fill_color[1] = 1.0f;
    brush.fill_color[2] = 1.0f;
    brush.fill_opacity = 1.0f;
    brush.outline_opacity = 0.0f;
    return brush;
}
