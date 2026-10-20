#include <pebble.h>
static Window *s_window;
static BitmapLayer *s_tick_layer;
static GBitmap *s_tick;
static TextLayer *s_common, *s_scientific, *s_stage;
static void window_load(Window *window) {
  Layer *root = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(root);
  window_set_background_color(window, GColorWhite);
  s_common = text_layer_create(GRect(0, 7, bounds.size.w, 32));
  text_layer_set_background_color(s_common, GColorClear);
  text_layer_set_text_color(s_common, GColorBlack);
  text_layer_set_font(s_common, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  text_layer_set_text_alignment(s_common, GTextAlignmentCenter);
  text_layer_set_text(s_common, "Deer Tick");
  layer_add_child(root, text_layer_get_layer(s_common));
  s_scientific = text_layer_create(GRect(0, 40, bounds.size.w, 23));
  text_layer_set_background_color(s_scientific, GColorClear);
  text_layer_set_text_color(s_scientific, GColorBlack);
  text_layer_set_font(s_scientific, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_scientific, GTextAlignmentCenter);
  text_layer_set_text(s_scientific, "Ixodes scapularis");
  layer_add_child(root, text_layer_get_layer(s_scientific));
  s_tick = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DEER_TICK);
  s_tick_layer = bitmap_layer_create(GRect(5, 59, bounds.size.w - 10, 154));
  bitmap_layer_set_bitmap(s_tick_layer, s_tick);
  bitmap_layer_set_compositing_mode(s_tick_layer, GCompOpSet);
  bitmap_layer_set_alignment(s_tick_layer, GAlignCenter);
  layer_add_child(root, bitmap_layer_get_layer(s_tick_layer));
  s_stage = text_layer_create(GRect(0, bounds.size.h - 26, bounds.size.w, 24));
  text_layer_set_background_color(s_stage, GColorClear);
  text_layer_set_text_color(s_stage, GColorBlack);
  text_layer_set_font(s_stage, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  text_layer_set_text_alignment(s_stage, GTextAlignmentCenter);
  text_layer_set_text(s_stage, "Adult female");
  layer_add_child(root, text_layer_get_layer(s_stage));
}
static void window_unload(Window *window) {
  text_layer_destroy(s_common);
  text_layer_destroy(s_scientific);
  text_layer_destroy(s_stage);
  bitmap_layer_destroy(s_tick_layer);
  gbitmap_destroy(s_tick);
}
int main(void) {
  s_window = window_create();
  window_set_window_handlers(s_window, (WindowHandlers){.load=window_load,.unload=window_unload});
  window_stack_push(s_window, true);
  app_event_loop();
  window_destroy(s_window);
}