#include "types.h"

uint64_t __readmsr(unsigned long __register)
{
	unsigned long __edx;
	unsigned long __eax;
	__asm__ ("rdmsr" : "=d"(__edx), "=a"(__eax) : "c"(__register));
	return (((uint64_t)__edx) << 32) | (uint64_t)__eax;
}

void resetTime()
{
	uint8_t* kernel_base = (uint8_t*)(__readmsr(0xC0000082) - 0x1C0);
	// Note args type (uint64_t*) could be incorrect (aka uint64_t or uint32_t) but im too lazy to check since it works
	// Note somewhere between 1.76 and 5.05 `sceSblSrtcSetTime()` was changed and few extra checks have been added using samu
	// So if you're backporting this you may not need or even find `sceSblSrtcClearTimeDifference()`
	// Finally `sceSblSrtcClearTimeDifference()` is also named `sceSblSrtcReset()` when the 1st argument is 15
	void(*sceSblSrtcClearTimeDifference)(uint64_t) = (void*)(kernel_base + 0x634690);
	void(*sceSblSrtcSetTime)(uint64_t*) = (void*)(kernel_base + 0x634090);
	sceSblSrtcClearTimeDifference(15);
	sceSblSrtcSetTime(14861963);
}

int _main(void)
{
	syscall(11, resetTime);
	return 0;
}
