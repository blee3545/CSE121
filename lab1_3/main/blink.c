#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_err.h"
#include "led_strip.h"

#define LED_GPIO 2

static led_strip_handle_t led;

static void blink_task(void *arg)
{
    (void)arg;

    while (1) {
        ESP_ERROR_CHECK(led_strip_set_pixel(led, 0, 16, 16, 16));
        ESP_ERROR_CHECK(led_strip_refresh(led));
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_ERROR_CHECK(led_strip_clear(led));
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void)
{
    const led_strip_config_t strip_config = {
        .strip_gpio_num = LED_GPIO,
        .max_leds = 1,
        .led_model = LED_MODEL_WS2812,
        .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
    };

    const led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000,
    };

    ESP_ERROR_CHECK(
        led_strip_new_rmt_device(&strip_config, &rmt_config, &led));

    xTaskCreate(blink_task, "blink_task", 2048, NULL, 5, NULL);
}
