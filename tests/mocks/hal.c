#include "app.h"

void hal_plot_led(u8 type, u8 index, u8 red, u8 green, u8 blue)
{
}

void hal_read_led(u8 type, u8 index, u8 *red, u8 *green, u8 *blue)
{
}

void hal_send_midi(u8 port, u8 status, u8 d1, u8 d2)
{
}

void hal_send_sysex(u8 port, const u8* data, u16 length)
{
}

void hal_read_flash(u32 offset, u8 *data, u32 length)
{
}

void hal_write_flash(u32 offset,const u8 *data, u32 length)
{
}

static u16 raw_ADC[64];

void sim_app_init()
{
	app_init(raw_ADC);
}

void sim_app_surface_event(u8 type, u8 index, u8 value)
{
	app_surface_event(type, index, value);
}

void sim_app_midi_event(u8 port, u8 status, u8 d1, u8 d2)
{
	app_midi_event(port, status, d1, d2);
}

void sim_app_timer_event()
{
	app_timer_event();
}
