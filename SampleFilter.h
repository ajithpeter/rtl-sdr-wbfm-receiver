#ifndef SAMPLEFILTER_H_
#define SAMPLEFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 1058400 Hz

* 0 Hz - 10000 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = 4.049592185137081 dB

* 22000 Hz - 529200 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -40.257177985524926 dB

*/

#define SAMPLEFILTER_TAP_NUM 117

typedef struct {
  float history[SAMPLEFILTER_TAP_NUM];
  unsigned int last_index;
} SampleFilter;

void SampleFilter_init(SampleFilter* f);
void SampleFilter_put(SampleFilter* f, float input);
float SampleFilter_get(SampleFilter* f);

#endif
