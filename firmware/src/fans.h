#ifndef YARR_FANS_H
#define YARR_FANS_H

extern int last_rpm[FAN_COUNT];

void fans_setup();
void fans_loop();
void measure_fan_rpm(byte i);

#endif /* !YARR_FANS_H */