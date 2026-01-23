 
 
 
 
 void CMU_Init()
 {
 GTM0.CMUGCLKNUM  = 0x0FFFF; // global divider = *1
  GTM0.CMUGCLKDEN  = 0x0FFFF;
  GTM0.CMUCLK3CTRL = 0x00000004; // sys_clk_period *5 = 62,5ns @ 80MH sys_clk
  GTM0.CMUCLKEN    = 0x00000080; // enable CMU clock 3
  status = GTM0.CMUCLKEN;
  if (status != 0x000000C0) {
    printf("ERROR: CMU clock 3 cannot be enabled\n");
    while(1);//Stay here if clock could not be enabled
  }
 }

  void TIM_Init()
 {
  GTM0.TIM10CTRL   = 0x03002F01;//to measure GTM0AT0O0
  GTM0.TIM11CTRL   = 0x03002F01;//to measure GTM0AT0O1
  GTM0.TIM11IRQEN  = 0x00000001;//enable NEWVAL IRQ
 }

void PWM_Init()
{
  printf ("Configure CMU\n");
  GTM0.CMUGCLKNUM  = 0x0FFFF; // global divider = *1
  GTM0.CMUGCLKDEN  = 0x0FFFF;
  GTM0.CMUCLK3CTRL = 0x00000004; // sys_clk_period *5 = 62,5ns @ 80MH sys_clk
  GTM0.CMUCLKEN    = 0x00000080; // enable CMU clock 3
  status = GTM0.CMUCLKEN;
  if (status != 0x000000C0) {
    printf("ERROR: CMU clock 3 cannot be enabled\n");
    while(1);//Stay here if clock could not be enabled
  }

  printf ("Configure TIM\n");

  GTM0.TIM10CTRL   = 0x03002F01;//to measure GTM0AT0O0
  GTM0.TIM11CTRL   = 0x03002F01;//to measure GTM0AT0O1
  GTM0.TIM11IRQEN  = 0x00000001;//enable NEWVAL IRQ



  printf("Configure DTM24 (connected to outputs of ATOM0 channel 0 to 3)\n");
  GTM0.DTM24CHCTRL2 = 0x88888800; // enable dead time channel 1,2,3
  GTM0.DTM241DTV    = 0x00140014; // RELRISE=100, RELFALL=100 @sys_clk = 1,25µs
  GTM0.DTM242DTV    = 0x00140014; // RELRISE=100, RELFALL=100
  GTM0.DTM243DTV    = 0x00140014; // RELRISE=100, RELFALL=100
  
 
  printf("Channel 0 is master channel that defines period of PWM\n");
  GTM0.ATOM00CTRL = (mode_somp)+(sl_hi)+(trig_ccu0)+(cmu_clk3);
  printf("Channel 1 to 6 are synchronized to channel 1 and middle symmetrical\n");
  GTM0.ATOM01CTRL = (mode_somp)+(aru_off)+(sl_hi)+(rst_on_trig)+(cmu_clk3);
  GTM0.ATOM02CTRL = (mode_somp)+(aru_off)+(sl_lo)+(rst_on_trig)+(cmu_clk3);
  GTM0.ATOM03CTRL = (mode_somp)+(aru_off)+(sl_hi)+(rst_on_trig)+(cmu_clk3);
  GTM0.ATOM04CTRL = (mode_somp)+(aru_off)+(sl_lo)+(rst_on_trig)+(cmu_clk3);
  GTM0.ATOM05CTRL = (mode_somp)+(aru_off)+(sl_hi)+(rst_on_trig)+(cmu_clk3);
  GTM0.ATOM06CTRL = (mode_somp)+(aru_off)+(sl_lo)+(rst_on_trig)+(cmu_clk3);
  printf("Channel 7 triggers reload of SRx register\n");
  GTM0.ATOM07CTRL = (mode_somp)+(aru_off)+(sl_hi)+(cmu_clk3)+(trig_ccu0);
}