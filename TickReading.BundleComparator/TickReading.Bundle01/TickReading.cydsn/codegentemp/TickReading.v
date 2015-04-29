// ======================================================================
// TickReading.v generated from TopDesign.cysch
// 04/28/2015 at 16:08
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PANTHER 2
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 1
`define CYDEV_CHIP_REV_EXPECT 3
`define CYDEV_CHIP_DIE_ACTUAL 1
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC5 2
`define CYDEV_CHIP_MEMBER_5A 2
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 1
`define CYDEV_CHIP_MEMBER_USED 1
`define CYDEV_CHIP_REVISION_USED 3
// CharLCD_v1_60(ConversionRoutines=true, CUSTOM0=0,E,8,8,8,E,0, CUSTOM1=0,A,A,4,4,4,0, CUSTOM2=0,E,A,E,8,8,0, CUSTOM3=0,E,A,C,A,A,0, CUSTOM4=0,E,8,C,8,E,0, CUSTOM5=0,E,8,E,2,E,0, CUSTOM6=0,E,8,E,2,E,0, CUSTOM7=0,4,4,4,0,4,0, CustomCharacterSet=0, CY_COMPONENT_NAME=CharLCD_v1_60, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=LCD, CY_INSTANCE_SHORT_NAME=LCD, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=60, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=LCD, )
module CharLCD_v1_60_0 ;



	wire [6:0] tmpOE__LCDPort_net;
	wire [6:0] tmpFB_6__LCDPort_net;
	wire [6:0] tmpIO_6__LCDPort_net;
	wire [0:0] tmpINTERRUPT_0__LCDPort_net;
	electrical [0:0] tmpSIOVREF__LCDPort_net;

	cy_psoc3_pins_v1_10
		#(.id("48415911-11c2-470c-a0a8-822e65de63e0/ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(21'b110_110_110_110_110_110_110),
		  .ibuf_enabled(7'b1_1_1_1_1_1_1),
		  .init_dr_st(7'b0_0_0_0_0_0_0),
		  .input_sync(7'b1_1_1_1_1_1_1),
		  .intr_mode(14'b00_00_00_00_00_00_00),
		  .io_voltage(", , , , , , "),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(7'b0_0_0_0_0_0_0),
		  .output_conn(7'b0_0_0_0_0_0_0),
		  .output_sync(7'b0_0_0_0_0_0_0),
		  .pin_aliases(",,,,,,"),
		  .pin_mode("OOOOOOO"),
		  .por_state(4),
		  .use_annotation(7'b0_0_0_0_0_0_0),
		  .sio_group_cnt(0),
		  .sio_hyst(7'b0_0_0_0_0_0_0),
		  .sio_ibuf(""),
		  .sio_info(14'b00_00_00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(7'b0_0_0_0_0_0_0),
		  .spanning(0),
		  .vtrip(14'b10_10_10_10_10_10_10),
		  .width(7))
		LCDPort
		 (.oe(tmpOE__LCDPort_net),
		  .y({7'b0}),
		  .fb({tmpFB_6__LCDPort_net[6:0]}),
		  .io({tmpIO_6__LCDPort_net[6:0]}),
		  .siovref(tmpSIOVREF__LCDPort_net),
		  .interrupt({tmpINTERRUPT_0__LCDPort_net[0:0]}));

	assign tmpOE__LCDPort_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{7'b1111111} : {7'b1111111};



endmodule

// Component: B_PWM_v2_20
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v2_20"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v2_20\B_PWM_v2_20.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v2_20"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v2_20\B_PWM_v2_20.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// PWM_v2_20(CaptureMode=0, Compare1_16=true, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=250, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=999, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=true, TriggerMode=0, UDB16=true, UDB8=false, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP16, CY_COMPONENT_NAME=PWM_v2_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PWM, CY_INSTANCE_SHORT_NAME=PWM, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PWM, )
module PWM_v2_20_1 (
    pwm2,
    tc,
    clock,
    reset,
    pwm1,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    output      pwm2;
    output      tc;
    input       clock;
    input       reset;
    output      pwm1;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_113;
          wire  Net_114;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v2_20 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 16;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 1;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: B_Counter_v2_20
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_20"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_20\B_Counter_v2_20.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_20"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v2_20\B_Counter_v2_20.v"
`endif

// Counter_v2_20(CaptureMode=1, CaptureModeSoftware=0, ClockMode=0, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=128, CONTROL3=0, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG24, CySetRegReplacementString=CY_SET_REG24, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=true, InterruptOnCompare=false, InterruptOnOverUnderFlow=true, InterruptOnTC=false, Period=16777215, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, ReloadOnCapture=true, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=24, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, UDB16=false, UDB24=true, UDB32=false, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC24, CY_COMPONENT_NAME=Counter_v2_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Hall_Counter, CY_INSTANCE_SHORT_NAME=Hall_Counter, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Hall_Counter, )
module Counter_v2_20_2 (
    clock,
    comp,
    tc,
    reset,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       clock;
    output      comp;
    output      tc;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 1;
    parameter ClockMode = 0;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 1;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 24;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_54;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v2_20 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 1;
    defparam CounterUDB.ClockMode = 0;
    defparam CounterUDB.CompareMode = 1;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 1;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 24;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Counter_v2_20(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=49, CONTROL3=0, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=true, InterruptOnTC=false, Period=99, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=false, ReloadOnReset=true, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=1, UDB16=true, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_COMPONENT_NAME=Counter_v2_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Lines_Per_Frame_Counter, CY_INSTANCE_SHORT_NAME=Lines_Per_Frame_Counter, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Lines_Per_Frame_Counter, )
module Counter_v2_20_3 (
    clock,
    comp,
    tc,
    reset,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       clock;
    output      comp;
    output      tc;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 0;
    parameter CompareMode = 0;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 0;
    parameter ReloadOnReset = 1;
    parameter Resolution = 16;
    parameter RunMode = 1;
    parameter UseInterrupt = 1;

          wire  Net_54;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v2_20 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 0;
    defparam CounterUDB.CompareMode = 0;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 0;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 16;
    defparam CounterUDB.RunMode = 1;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: B_Timer_v2_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_30"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_30\B_Timer_v2_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_30\B_Timer_v2_30.v"
`endif

// Timer_v2_30(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=true, CaptureMode=2, CONTROL3=0, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeviceFamily=PSoC3, EnableMode=2, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, HWCaptureCounterEnabled=false, InterruptOnCapture=true, InterruptOnFIFOFull=false, InterruptOnTC=false, IntOnCapture=1, IntOnFIFOFull=0, IntOnTC=0, NumberOfCaptures=2, param45=1, Period=65535, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=rstSts, RunMode=0, SiliconRevision=3, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=true, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UsesHWEnable=1, VerilogSectionReplacementString=sT16, CY_COMPONENT_NAME=Timer_v2_30, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Line_Timer, CY_INSTANCE_SHORT_NAME=Line_Timer, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Line_Timer, )
module Timer_v2_30_4 (
    clock,
    reset,
    interrupt,
    enable,
    capture,
    trigger,
    capture_out,
    tc);
    input       clock;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       trigger;
    output      capture_out;
    output      tc;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC3";
    parameter InterruptOnCapture = 1;
    parameter InterruptOnTC = 0;
    parameter Resolution = 16;
    parameter SiliconRevision = "3";

          wire  Net_260;
          wire  Net_261;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_53;

    B_Timer_v2_30 TimerUDB (
        .reset(reset),
        .interrupt(Net_55),
        .enable(enable),
        .trigger(trigger),
        .capture_in(capture),
        .capture_out(capture_out),
        .tc(Net_53),
        .clock(clock));
    defparam TimerUDB.Capture_Count = 2;
    defparam TimerUDB.CaptureCounterEnabled = 0;
    defparam TimerUDB.CaptureMode = 2;
    defparam TimerUDB.EnableMode = 2;
    defparam TimerUDB.InterruptOnCapture = 1;
    defparam TimerUDB.Resolution = 16;
    defparam TimerUDB.RunMode = 0;
    defparam TimerUDB.TriggerMode = 0;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = enable;



endmodule

// Comp_v1_90(Hysteresis=0, Pd_Override=0, Polarity=1, PSOC5A=false, Speed=1, Sync=0, CY_COMPONENT_NAME=Comp_v1_90, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Camera_Comp, CY_INSTANCE_SHORT_NAME=Camera_Comp, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Camera_Comp, )
module Comp_v1_90_5 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_9;


    assign Net_9 = ~Net_1;



endmodule

// VDAC8_v1_80(Data_Source=0, Initial_Value=193, Strobe_Mode=0, VDAC_Range=0, VDAC_Speed=0, Voltage=772, CY_COMPONENT_NAME=VDAC8_v1_80, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Camera_Threshold, CY_INSTANCE_SHORT_NAME=Camera_Threshold, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=80, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Camera_Threshold, )
module VDAC8_v1_80_6 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 193;
    parameter Strobe_Mode = 0;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// PWM_v2_20(CaptureMode=0, Compare1_16=true, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=152, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=999, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=true, TriggerMode=0, UDB16=true, UDB8=false, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP16, CY_COMPONENT_NAME=PWM_v2_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=PWM_Steering, CY_INSTANCE_SHORT_NAME=PWM_Steering, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=PWM_Steering, )
module PWM_v2_20_7 (
    pwm2,
    tc,
    clock,
    reset,
    pwm1,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    output      pwm2;
    output      tc;
    input       clock;
    input       reset;
    output      pwm1;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v2_20 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 16;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 1;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// Comp_v1_90(Hysteresis=0, Pd_Override=0, Polarity=1, PSOC5A=false, Speed=0, Sync=0, CY_COMPONENT_NAME=Comp_v1_90, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Elevator_Comparator, CY_INSTANCE_SHORT_NAME=Elevator_Comparator, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Elevator_Comparator, )
module Comp_v1_90_8 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_9;


    assign Net_9 = ~Net_1;



endmodule

// VDAC8_v1_80(Data_Source=0, Initial_Value=200, Strobe_Mode=0, VDAC_Range=0, VDAC_Speed=0, Voltage=800, CY_COMPONENT_NAME=VDAC8_v1_80, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Elevator_Threshold, CY_INSTANCE_SHORT_NAME=Elevator_Threshold, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=80, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Elevator_Threshold, )
module VDAC8_v1_80_9 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 200;
    parameter Strobe_Mode = 0;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// Component: CyControlReg_v1_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_70\CyControlReg_v1_70.v"
`endif

// Component: mux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10\mux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10\mux_v1_10.v"
`endif

// Comp_v1_90(Hysteresis=0, Pd_Override=0, Polarity=1, PSOC5A=false, Speed=0, Sync=0, CY_COMPONENT_NAME=Comp_v1_90, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Elevator_Comparator_1, CY_INSTANCE_SHORT_NAME=Elevator_Comparator_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Elevator_Comparator_1, )
module Comp_v1_90_10 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_9;


    assign Net_9 = ~Net_1;



endmodule

// Counter_v2_20(CaptureMode=0, CaptureModeSoftware=0, ClockMode=3, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=1000, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=true, Period=1000, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=1, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_COMPONENT_NAME=Counter_v2_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=Wait_Counter, CY_INSTANCE_SHORT_NAME=Wait_Counter, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=Wait_Counter, )
module Counter_v2_20_11 (
    clock,
    comp,
    tc,
    reset,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       clock;
    output      comp;
    output      tc;
    input       reset;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 3;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 16;
    parameter RunMode = 1;
    parameter UseInterrupt = 1;

          wire  Net_54;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

    cy_psoc3_timer_v1_0 CounterHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_91),
        .kill(Net_82),
        .clock(clock),
        .tc(Net_48),
        .compare(Net_54),
        .interrupt(Net_42));

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_42;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_48;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = Net_95;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));



endmodule

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: AMux_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_60"
`include "$CYPRESS_DIR\..\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_60\AMux_v1_60.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_60\AMux_v1_60.v"
`endif

// Component: cy_vref_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "$CYPRESS_DIR\..\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\2.1\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`endif

// ADC_Vssa_v1_20(CY_COMPONENT_NAME=ADC_Vssa_v1_20, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=ADC_Vssa_1, CY_INSTANCE_SHORT_NAME=ADC_Vssa_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=20, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=ADC_DelSig_ADC_Vssa_1, )
module ADC_Vssa_v1_20_12 (
    vout);
    inout       vout;
    electrical  vout;




	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("15B3DB15-B7B3-4d62-A2DF-25EA392A7161"),
		  .name("Vssa (GND)"))
		vRef_1
		 (.vout(vout));




endmodule

// ADC_DelSig_v2_30(ADC_Charge_Pump_Clock=true, ADC_Clock=1, ADC_CLOCK_FREQUENCY=460000, ADC_Input_Mode=1, ADC_Input_Range=1, ADC_Input_Range_Config2=0, ADC_Input_Range_Config3=0, ADC_Input_Range_Config4=0, ADC_Power=1, ADC_Reference=0, ADC_Reference_Config2=0, ADC_Reference_Config3=0, ADC_Reference_Config4=0, ADC_Resolution=14, ADC_Resolution_Config2=16, ADC_Resolution_Config3=16, ADC_Resolution_Config4=16, Clock_Frequency=64000, Comment_Config1=Default Config, Comment_Config2=Second Config, Comment_Config3=Third Config, Comment_Config4=Fourth Config, Config1_Name=CFG1, Config2_Name=CFG2, Config3_Name=CFG3, Config4_Name=CFG4, Configs=1, Conversion_Mode=2, Conversion_Mode_Config2=2, Conversion_Mode_Config3=2, Conversion_Mode_Config4=2, Debug=false, DsmName=DSM4, Enable_Vref_Vss=false, Input_Buffer_Gain=1, Input_Buffer_Gain_Config2=1, Input_Buffer_Gain_Config3=1, Input_Buffer_Gain_Config4=1, Input_Buffer_Mode=1, Input_Buffer_Mode_Config2=1, Input_Buffer_Mode_Config3=1, Input_Buffer_Mode_Config4=1, PSOC5A=false, Ref_Voltage=1.024, Ref_Voltage_Config2=1.024, Ref_Voltage_Config3=1.024, Ref_Voltage_Config4=1.024, Sample_Rate=10000, Sample_Rate_Config2=10000, Sample_Rate_Config3=10000, Sample_Rate_Config4=10000, sRate_Err=false, Start_of_Conversion=0, Vdda_Value=5, CY_COMPONENT_NAME=ADC_DelSig_v2_30, CY_CONTROL_FILE=<:default:>, CY_FITTER_NAME=ADC_DelSig, CY_INSTANCE_SHORT_NAME=ADC_DelSig, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=cydsfit No Version Information Found, INSTANCE_NAME=ADC_DelSig, )
module ADC_DelSig_v2_30_13 (
    vplus,
    vminus,
    soc,
    eoc,
    aclk,
    nVref);
    inout       vplus;
    electrical  vplus;
    inout       vminus;
    electrical  vminus;
    input       soc;
    output      eoc;
    input       aclk;
    inout       nVref;
    electrical  nVref;


          wire  aclock;
          wire [3:0] mod_dat;
          wire  mod_reset;
          wire  Net_1;
    electrical  Net_2;
    electrical  Net_3;
          wire  Net_4;
          wire [7:0] Net_5;
          wire  Net_6;
          wire  Net_7;
          wire  Net_8;
          wire [7:0] Net_9;
          wire  Net_10;
    electrical  Net_11;
    electrical  Net_12;
    electrical  Net_13;
    electrical  Net_686;
    electrical  Net_690;
    electrical  Net_681;
    electrical  Net_677;
    electrical  Net_570;
          wire  Net_488;
          wire  Net_482;
          wire  Net_481;
          wire  Net_478;
          wire  Net_438;
          wire [3:0] Net_471;
          wire [3:0] Net_470;
    electrical  Net_352;
    electrical  Net_580;
    electrical  Net_349;
    electrical  Net_573;
    electrical  Net_257;
          wire  Net_487;
          wire  Net_40;
    electrical  Net_520;

    cy_psoc3_decimator_v1_0 DEC (
        .aclock(aclock),
        .mod_dat(mod_dat[3:0]),
        .ext_start(soc),
        .mod_reset(mod_reset),
        .interrupt(eoc));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_481));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_482));


	cy_clock_v1_0
		#(.id("1e8f4f01-953e-441e-ab54-a848fe7d73b4/edd15f43-b66b-457b-be3a-5342345270c8"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("2173913043.47826"),
		  .is_direct(0),
		  .is_digital(0))
		theACLK
		 (.clock_out(Net_40));


	// Clock_VirtualMux (cy_virtualmux_v1_0)
	assign Net_488 = Net_40;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_520, Net_681);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_580, Net_349);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_573, Net_257);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_349));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_257));


	cy_clock_v1_0
		#(.id("1e8f4f01-953e-441e-ab54-a848fe7d73b4/b7604721-db56-4477-98c2-8fae77869066"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("543478260.869565"),
		  .is_direct(0),
		  .is_digital(1))
		Ext_CP_Clk
		 (.clock_out(Net_487));


	// cy_analog_virtualmux_5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_5_connect(Net_570, Net_352);
	defparam cy_analog_virtualmux_5_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_5 (
        .noconnect(Net_352));

    cy_psoc3_ds_mod_v4_0 DSM4 (
        .vplus(vplus),
        .vminus(Net_520),
        .modbit(Net_7),
        .reset_udb(Net_8),
        .aclock(Net_488),
        .mod_dat(Net_471[3:0]),
        .dout_udb(Net_9[7:0]),
        .reset_dec(mod_reset),
        .dec_clock(Net_478),
        .extclk_cp_udb(Net_487),
        .clk_udb(1'b0),
        .ext_pin_1(Net_580),
        .ext_pin_2(Net_573),
        .ext_vssa(Net_570),
        .qtz_ref(Net_677));
    defparam DSM4.resolution = 14;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_7));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_8));

	// Clock_VirtualMux_2 (cy_virtualmux_v1_0)
	assign mod_dat[3:0] = Net_471[3:0];

	// Clock_VirtualMux_3 (cy_virtualmux_v1_0)
	assign aclock = Net_478;

    // -- AMux AMux start -- ***
    // -- Mux A --
    
    cy_psoc3_amux_v1_0 AMux(
        .muxin({
            Net_690,
            Net_11
            }),
        .vout(Net_681)
        );
    
    defparam AMux.muxin_width = 2;
    defparam AMux.init_mux_sel = 2'h0;
    defparam AMux.one_active = 0;
    defparam AMux.connect_mode = 1;
    
    // -- AMux AMux end --

	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_677, Net_686);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_12));

	// cy_analog_virtualmux_6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_6_connect(Net_690, Net_686);
	defparam cy_analog_virtualmux_6_connect.sig_width = 1;

    ADC_Vssa_v1_20_12 ADC_Vssa_1 (
        .vout(Net_11));



endmodule

// top
module top ;

    electrical  Net_2209;
          wire  Net_2208;
          wire  Net_2207;
          wire  Net_2206;
    electrical  Net_2205;
          wire  Net_2145;
          wire  Net_2155;
          wire  Net_2154;
          wire  Net_2153;
          wire  Net_2152;
          wire  Net_2151;
          wire  Net_2150;
          wire  Net_2149;
          wire  Net_2148;
          wire  Net_2147;
          wire  Net_2109;
          wire  Net_2101;
          wire  Net_2100;
          wire  Net_2099;
          wire  Net_2098;
          wire  Net_2097;
          wire  Net_2096;
          wire  Net_2094;
          wire  Net_2093;
          wire [7:0] Net_1963;
          wire  Net_1962;
          wire  Net_1953;
          wire  Net_1910;
          wire  Net_1909;
          wire  Net_1908;
          wire  Net_1907;
          wire  Net_1906;
          wire  Net_1905;
          wire  Net_1904;
          wire  Net_1903;
          wire  Net_1902;
          wire  Net_1901;
          wire  Net_1900;
          wire  Net_1899;
          wire [7:0] Net_1518;
          wire  Net_1517;
          wire  Net_1873;
          wire  Net_1884;
          wire  Net_1822;
          wire  Net_1821;
          wire  Net_1820;
          wire  Net_1837;
          wire  Net_1836;
          wire  Net_1835;
          wire  Net_1834;
          wire  Net_1833;
          wire  Net_1832;
          wire  Net_1445;
          wire  Net_1136;
          wire  Net_675;
          wire  Net_727;
          wire  Net_726;
          wire  Net_725;
          wire  Net_724;
          wire  Net_723;
          wire  Net_1166;
          wire  Net_1165;
          wire  Net_1164;
          wire  Net_1163;
          wire  Net_1162;
          wire  Net_1161;
          wire  Net_1160;
          wire  Net_1159;
          wire  Net_1158;
          wire  Net_1157;
          wire  Net_1156;
          wire  Net_1155;
          wire  Net_2146;
          wire  Net_2114;
    electrical  Net_1949;
          wire  Net_2103;
    electrical  Net_2102;
          wire  Net_2105;
          wire  Net_2049;
          wire  Net_2046;
          wire  Net_2071;
          wire  Net_1933;
          wire  Net_1932;
          wire  Net_1957;
          wire  Net_1927;
          wire  Net_1930;
          wire  Net_1924;
    electrical  Net_1947;
          wire  Net_1950;
          wire  Net_1853;
          wire  Net_1208;
          wire  Net_1824;
          wire  Net_1809;
          wire  Net_1790;
          wire  Net_1254;
          wire  Net_1535;
          wire  Net_1214;
    electrical  Net_1527;
          wire  Net_1607;
    electrical  Net_1446;
          wire  Net_1816;
          wire  Net_1074;
          wire  Net_1169;
          wire  Net_965;
          wire  Net_633;
          wire  Net_630;
          wire  Net_658;

    CharLCD_v1_60_0 LCD ();

	wire [0:0] tmpOE__Hall_To_PSOC_net;
	wire [0:0] tmpIO_0__Hall_To_PSOC_net;
	wire [0:0] tmpINTERRUPT_0__Hall_To_PSOC_net;
	electrical [0:0] tmpSIOVREF__Hall_To_PSOC_net;

	cy_psoc3_pins_v1_10
		#(.id("4c15b41e-e284-4978-99e7-5aaee19bd0ce"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		Hall_To_PSOC
		 (.oe(tmpOE__Hall_To_PSOC_net),
		  .y({1'b0}),
		  .fb({Net_965}),
		  .io({tmpIO_0__Hall_To_PSOC_net[0:0]}),
		  .siovref(tmpSIOVREF__Hall_To_PSOC_net),
		  .interrupt({tmpINTERRUPT_0__Hall_To_PSOC_net[0:0]}));

	assign tmpOE__Hall_To_PSOC_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    PWM_v2_20_1 PWM (
        .reset(1'b0),
        .clock(Net_1169),
        .tc(Net_1156),
        .pwm1(Net_1157),
        .pwm2(Net_1158),
        .interrupt(Net_1159),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_2071),
        .ph1(Net_1165),
        .ph2(Net_1166));
    defparam PWM.Resolution = 16;

    Counter_v2_20_2 Hall_Counter (
        .reset(Net_630),
        .tc(Net_658),
        .comp(Net_723),
        .clock(Net_633),
        .interrupt(Net_1074),
        .enable(1'b0),
        .capture(Net_965),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Net_1169));
    defparam Hall_Counter.CaptureMode = 1;
    defparam Hall_Counter.ClockMode = 0;
    defparam Hall_Counter.CompareMode = 1;
    defparam Hall_Counter.CompareStatusEdgeSense = 1;
    defparam Hall_Counter.EnableMode = 0;
    defparam Hall_Counter.ReloadOnCapture = 1;
    defparam Hall_Counter.ReloadOnCompare = 0;
    defparam Hall_Counter.ReloadOnOverUnder = 1;
    defparam Hall_Counter.ReloadOnReset = 1;
    defparam Hall_Counter.Resolution = 24;
    defparam Hall_Counter.RunMode = 0;
    defparam Hall_Counter.UseInterrupt = 1;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_630));


	cy_clock_v1_0
		#(.id("a3b88bab-82fd-4983-b7b1-0cac2fc09889"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		BUS_CLK
		 (.clock_out(Net_633));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ISR_Hall
		 (.int_signal(Net_1074));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ISR_Overflow
		 (.int_signal(Net_658));


	wire [0:0] tmpOE__Input_LED_net;
	wire [0:0] tmpFB_0__Input_LED_net;
	wire [0:0] tmpIO_0__Input_LED_net;
	wire [0:0] tmpINTERRUPT_0__Input_LED_net;
	electrical [0:0] tmpSIOVREF__Input_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("52f31aa9-2f0a-497d-9a1f-1424095e13e6"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Input_LED
		 (.oe(tmpOE__Input_LED_net),
		  .y({Net_965}),
		  .fb({tmpFB_0__Input_LED_net[0:0]}),
		  .io({tmpIO_0__Input_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_LED_net),
		  .interrupt({tmpINTERRUPT_0__Input_LED_net[0:0]}));

	assign tmpOE__Input_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_2046));


	cy_clock_v1_0
		#(.id("60464977-ebae-4058-bfc6-55931780bb23"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("10000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_Hall
		 (.clock_out(Net_1169));



    assign Net_1809 = ~Net_1254;


	cy_isr_v1_0
		#(.int_type(2'b10))
		ISR_100_Lines
		 (.int_signal(Net_1535));



	cy_clock_v1_0
		#(.id("8e97f775-beac-4809-bfa7-db24c60b7899"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_1214));


	wire [0:0] tmpOE__Vertical_Sync_Frame_net;
	wire [0:0] tmpIO_0__Vertical_Sync_Frame_net;
	wire [0:0] tmpINTERRUPT_0__Vertical_Sync_Frame_net;
	electrical [0:0] tmpSIOVREF__Vertical_Sync_Frame_net;

	cy_psoc3_pins_v1_10
		#(.id("5bff87c2-b965-4cf8-9044-6536e42eb338"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		Vertical_Sync_Frame
		 (.oe(tmpOE__Vertical_Sync_Frame_net),
		  .y({1'b0}),
		  .fb({Net_1254}),
		  .io({tmpIO_0__Vertical_Sync_Frame_net[0:0]}),
		  .siovref(tmpSIOVREF__Vertical_Sync_Frame_net),
		  .interrupt({tmpINTERRUPT_0__Vertical_Sync_Frame_net[0:0]}));

	assign tmpOE__Vertical_Sync_Frame_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Counter_v2_20_3 Lines_Per_Frame_Counter (
        .reset(Net_1809),
        .tc(Net_1535),
        .comp(Net_1816),
        .clock(Net_1214),
        .interrupt(Net_1832),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Net_1208));
    defparam Lines_Per_Frame_Counter.CaptureMode = 0;
    defparam Lines_Per_Frame_Counter.ClockMode = 0;
    defparam Lines_Per_Frame_Counter.CompareMode = 0;
    defparam Lines_Per_Frame_Counter.CompareStatusEdgeSense = 1;
    defparam Lines_Per_Frame_Counter.EnableMode = 0;
    defparam Lines_Per_Frame_Counter.ReloadOnCapture = 0;
    defparam Lines_Per_Frame_Counter.ReloadOnCompare = 0;
    defparam Lines_Per_Frame_Counter.ReloadOnOverUnder = 0;
    defparam Lines_Per_Frame_Counter.ReloadOnReset = 1;
    defparam Lines_Per_Frame_Counter.Resolution = 16;
    defparam Lines_Per_Frame_Counter.RunMode = 1;
    defparam Lines_Per_Frame_Counter.UseInterrupt = 1;

    Timer_v2_30_4 Line_Timer (
        .reset(Net_1535),
        .interrupt(Net_1790),
        .enable(Net_1816),
        .trigger(1'b0),
        .capture(Net_1607),
        .capture_out(Net_1821),
        .tc(Net_1822),
        .clock(Net_1214));
    defparam Line_Timer.CaptureCount = 2;
    defparam Line_Timer.CaptureCounterEnabled = 0;
    defparam Line_Timer.DeviceFamily = "PSoC3";
    defparam Line_Timer.InterruptOnCapture = 1;
    defparam Line_Timer.InterruptOnTC = 0;
    defparam Line_Timer.Resolution = 16;
    defparam Line_Timer.SiliconRevision = "3";

	wire [0:0] tmpOE__Steering_Output_net;
	wire [0:0] tmpFB_0__Steering_Output_net;
	wire [0:0] tmpIO_0__Steering_Output_net;
	wire [0:0] tmpINTERRUPT_0__Steering_Output_net;
	electrical [0:0] tmpSIOVREF__Steering_Output_net;

	cy_psoc3_pins_v1_10
		#(.id("d7e1e28f-db4b-44aa-9bca-48de4020f615"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Steering_Output
		 (.oe(tmpOE__Steering_Output_net),
		  .y({Net_1884}),
		  .fb({tmpFB_0__Steering_Output_net[0:0]}),
		  .io({tmpIO_0__Steering_Output_net[0:0]}),
		  .siovref(tmpSIOVREF__Steering_Output_net),
		  .interrupt({tmpINTERRUPT_0__Steering_Output_net[0:0]}));

	assign tmpOE__Steering_Output_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Horizontal_Sync_Line_net;
	wire [0:0] tmpIO_0__Horizontal_Sync_Line_net;
	wire [0:0] tmpINTERRUPT_0__Horizontal_Sync_Line_net;
	electrical [0:0] tmpSIOVREF__Horizontal_Sync_Line_net;

	cy_psoc3_pins_v1_10
		#(.id("6f5ca5b2-aa41-40f1-933c-95f393fce9cb"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b00),
		  .width(1))
		Horizontal_Sync_Line
		 (.oe(tmpOE__Horizontal_Sync_Line_net),
		  .y({1'b0}),
		  .fb({Net_1824}),
		  .io({tmpIO_0__Horizontal_Sync_Line_net[0:0]}),
		  .siovref(tmpSIOVREF__Horizontal_Sync_Line_net),
		  .interrupt({tmpINTERRUPT_0__Horizontal_Sync_Line_net[0:0]}));

	assign tmpOE__Horizontal_Sync_Line_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Composite_Video_net;
	wire [0:0] tmpFB_0__Composite_Video_net;
	wire [0:0] tmpIO_0__Composite_Video_net;
	wire [0:0] tmpINTERRUPT_0__Composite_Video_net;
	electrical [0:0] tmpSIOVREF__Composite_Video_net;

	cy_psoc3_pins_v1_10
		#(.id("05a9c8de-3ba2-4909-8250-95fdc61c0bf4"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Composite_Video
		 (.oe(tmpOE__Composite_Video_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Composite_Video_net[0:0]}),
		  .analog({Net_1446}),
		  .io({tmpIO_0__Composite_Video_net[0:0]}),
		  .siovref(tmpSIOVREF__Composite_Video_net),
		  .interrupt({tmpINTERRUPT_0__Composite_Video_net[0:0]}));

	assign tmpOE__Composite_Video_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Comp_v1_90_5 Camera_Comp (
        .Vplus(Net_1446),
        .CmpOut(Net_1607),
        .Vminus(Net_1527),
        .clock(Net_1214));


    assign Net_1208 = ~Net_1824;


	cy_clock_v1_0
		#(.id("6b954592-2f12-4dc5-8405-c732ba99ae1a"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("10000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_Steering
		 (.clock_out(Net_1853));



	cy_isr_v1_0
		#(.int_type(2'b00))
		ISR_50_Lines
		 (.int_signal(Net_1790));


    VDAC8_v1_80_6 Camera_Threshold (
        .strobe(1'b0),
        .data(8'b00000000),
        .vOut(Net_1527));
    defparam Camera_Threshold.Data_Source = 0;
    defparam Camera_Threshold.Initial_Value = 193;
    defparam Camera_Threshold.Strobe_Mode = 0;

    PWM_v2_20_7 PWM_Steering (
        .reset(1'b0),
        .clock(Net_1853),
        .tc(Net_1900),
        .pwm1(Net_1901),
        .pwm2(Net_1902),
        .interrupt(Net_1903),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_1884),
        .ph1(Net_1909),
        .ph2(Net_1910));
    defparam PWM_Steering.Resolution = 16;

	wire [0:0] tmpOE__elevator_test_net;
	wire [0:0] tmpFB_0__elevator_test_net;
	wire [0:0] tmpIO_0__elevator_test_net;
	wire [0:0] tmpINTERRUPT_0__elevator_test_net;
	electrical [0:0] tmpSIOVREF__elevator_test_net;

	cy_psoc3_pins_v1_10
		#(.id("f52d80b9-837f-4dfe-82ed-a6933ebdfba8"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		elevator_test
		 (.oe(tmpOE__elevator_test_net),
		  .y({Net_1957}),
		  .fb({tmpFB_0__elevator_test_net[0:0]}),
		  .io({tmpIO_0__elevator_test_net[0:0]}),
		  .siovref(tmpSIOVREF__elevator_test_net),
		  .interrupt({tmpINTERRUPT_0__elevator_test_net[0:0]}));

	assign tmpOE__elevator_test_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_1_net;
	wire [0:0] tmpFB_0__Pin_1_net;
	wire [0:0] tmpIO_0__Pin_1_net;
	wire [0:0] tmpINTERRUPT_0__Pin_1_net;
	electrical [0:0] tmpSIOVREF__Pin_1_net;

	cy_psoc3_pins_v1_10
		#(.id("1909a61c-19e6-4443-bf2c-2c646a907ff4"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Pin_1
		 (.oe(tmpOE__Pin_1_net),
		  .y({Net_2049}),
		  .fb({tmpFB_0__Pin_1_net[0:0]}),
		  .io({tmpIO_0__Pin_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_1_net),
		  .interrupt({tmpINTERRUPT_0__Pin_1_net[0:0]}));

	assign tmpOE__Pin_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__elevator_input_2_net;
	wire [0:0] tmpFB_0__elevator_input_2_net;
	wire [0:0] tmpIO_0__elevator_input_2_net;
	wire [0:0] tmpINTERRUPT_0__elevator_input_2_net;
	electrical [0:0] tmpSIOVREF__elevator_input_2_net;

	cy_psoc3_pins_v1_10
		#(.id("a4c92df3-c989-4511-9f63-cb82aaf1146f"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		elevator_input_2
		 (.oe(tmpOE__elevator_input_2_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__elevator_input_2_net[0:0]}),
		  .analog({Net_2102}),
		  .io({tmpIO_0__elevator_input_2_net[0:0]}),
		  .siovref(tmpSIOVREF__elevator_input_2_net),
		  .interrupt({tmpINTERRUPT_0__elevator_input_2_net[0:0]}));

	assign tmpOE__elevator_input_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__drive_output_2_net;
	wire [0:0] tmpFB_0__drive_output_2_net;
	wire [0:0] tmpIO_0__drive_output_2_net;
	wire [0:0] tmpINTERRUPT_0__drive_output_2_net;
	electrical [0:0] tmpSIOVREF__drive_output_2_net;

	cy_psoc3_pins_v1_10
		#(.id("8e041183-0ff9-4856-9303-0316f8423384"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		drive_output_2
		 (.oe(tmpOE__drive_output_2_net),
		  .y({Net_1933}),
		  .fb({tmpFB_0__drive_output_2_net[0:0]}),
		  .io({tmpIO_0__drive_output_2_net[0:0]}),
		  .siovref(tmpSIOVREF__drive_output_2_net),
		  .interrupt({tmpINTERRUPT_0__drive_output_2_net[0:0]}));

	assign tmpOE__drive_output_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__drive_output_1_net;
	wire [0:0] tmpFB_0__drive_output_1_net;
	wire [0:0] tmpIO_0__drive_output_1_net;
	wire [0:0] tmpINTERRUPT_0__drive_output_1_net;
	electrical [0:0] tmpSIOVREF__drive_output_1_net;

	cy_psoc3_pins_v1_10
		#(.id("1c91d504-b075-44c4-91ba-78dfa67ab5af"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		drive_output_1
		 (.oe(tmpOE__drive_output_1_net),
		  .y({Net_1932}),
		  .fb({tmpFB_0__drive_output_1_net[0:0]}),
		  .io({tmpIO_0__drive_output_1_net[0:0]}),
		  .siovref(tmpSIOVREF__drive_output_1_net),
		  .interrupt({tmpINTERRUPT_0__drive_output_1_net[0:0]}));

	assign tmpOE__drive_output_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_1933 = Net_1930 & Net_1924;


    assign Net_1932 = Net_1927 & Net_1930;

	wire [0:0] tmpOE__elevator_input_net;
	wire [0:0] tmpFB_0__elevator_input_net;
	wire [0:0] tmpIO_0__elevator_input_net;
	wire [0:0] tmpINTERRUPT_0__elevator_input_net;
	electrical [0:0] tmpSIOVREF__elevator_input_net;

	cy_psoc3_pins_v1_10
		#(.id("d5ddc964-5cda-4c0e-80d5-5fa7de9fd6a5"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b0),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		elevator_input
		 (.oe(tmpOE__elevator_input_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__elevator_input_net[0:0]}),
		  .analog({Net_1947}),
		  .io({tmpIO_0__elevator_input_net[0:0]}),
		  .siovref(tmpSIOVREF__elevator_input_net),
		  .interrupt({tmpINTERRUPT_0__elevator_input_net[0:0]}));

	assign tmpOE__elevator_input_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("ddd0ed57-a776-47f0-9c64-b12be4357136"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		BUS_CLK_1
		 (.clock_out(Net_1950));


    Comp_v1_90_8 Elevator_Comparator (
        .Vplus(Net_1947),
        .CmpOut(Net_1957),
        .Vminus(Net_1949),
        .clock(Net_1950));

    VDAC8_v1_80_9 Elevator_Threshold (
        .strobe(1'b0),
        .data(8'b00000000),
        .vOut(Net_1949));
    defparam Elevator_Threshold.Data_Source = 0;
    defparam Elevator_Threshold.Initial_Value = 200;
    defparam Elevator_Threshold.Strobe_Mode = 0;


	cy_isr_v1_0
		#(.int_type(2'b00))
		ISR_Elevator
		 (.int_signal(Net_1957));



    assign Net_1927 = ~Net_1924;

    CyControlReg_v1_70 Drive_Control_Reg (
        .control_1(Net_2049),
        .control_2(Net_2093),
        .control_3(Net_2094),
        .control_0(Net_1924),
        .control_4(Net_2096),
        .control_5(Net_2097),
        .control_6(Net_2098),
        .control_7(Net_2099),
        .clock(1'b0),
        .reset(1'b0));
    defparam Drive_Control_Reg.Bit0Mode = 0;
    defparam Drive_Control_Reg.Bit1Mode = 0;
    defparam Drive_Control_Reg.Bit2Mode = 0;
    defparam Drive_Control_Reg.Bit3Mode = 0;
    defparam Drive_Control_Reg.Bit4Mode = 0;
    defparam Drive_Control_Reg.Bit5Mode = 0;
    defparam Drive_Control_Reg.Bit6Mode = 0;
    defparam Drive_Control_Reg.Bit7Mode = 0;
    defparam Drive_Control_Reg.BitValue = 0;
    defparam Drive_Control_Reg.BusDisplay = 0;
    defparam Drive_Control_Reg.ExtrReset = 0;
    defparam Drive_Control_Reg.NumOutputs = 2;

    // -- Mux start --
    if (1)
    begin : mux_1
        reg  tmp__mux_1_reg;
        always @(Net_2046 or Net_2071 or Net_2049)
        begin
            case (Net_2049)
                1'b0 :  tmp__mux_1_reg = Net_2046;
                1'b1 :  tmp__mux_1_reg = Net_2071;
            endcase
        end
        assign Net_1930 = tmp__mux_1_reg;
    end
    // -- Mux end --

	wire [0:0] tmpOE__Pin_2_net;
	wire [0:0] tmpFB_0__Pin_2_net;
	wire [0:0] tmpIO_0__Pin_2_net;
	wire [0:0] tmpINTERRUPT_0__Pin_2_net;
	electrical [0:0] tmpSIOVREF__Pin_2_net;

	cy_psoc3_pins_v1_10
		#(.id("22916991-3652-4279-8489-e133c6ad8503"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Pin_2
		 (.oe(tmpOE__Pin_2_net),
		  .y({Net_1930}),
		  .fb({tmpFB_0__Pin_2_net[0:0]}),
		  .io({tmpIO_0__Pin_2_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_2_net),
		  .interrupt({tmpINTERRUPT_0__Pin_2_net[0:0]}));

	assign tmpOE__Pin_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Comp_v1_90_10 Elevator_Comparator_1 (
        .Vplus(Net_2102),
        .CmpOut(Net_2103),
        .Vminus(Net_1949),
        .clock(Net_2105));


	cy_clock_v1_0
		#(.id("48157e21-cdf4-4b37-a021-223049b9096d"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		BUS_CLK_2
		 (.clock_out(Net_2105));


	wire [0:0] tmpOE__Pin_3_net;
	wire [0:0] tmpFB_0__Pin_3_net;
	wire [0:0] tmpIO_0__Pin_3_net;
	wire [0:0] tmpINTERRUPT_0__Pin_3_net;
	electrical [0:0] tmpSIOVREF__Pin_3_net;

	cy_psoc3_pins_v1_10
		#(.id("9ba1fe5d-726a-46d3-bed3-90458441ab03"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Pin_3
		 (.oe(tmpOE__Pin_3_net),
		  .y({Net_1924}),
		  .fb({tmpFB_0__Pin_3_net[0:0]}),
		  .io({tmpIO_0__Pin_3_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_3_net),
		  .interrupt({tmpINTERRUPT_0__Pin_3_net[0:0]}));

	assign tmpOE__Pin_3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		ISR_Elevator_2
		 (.int_signal(Net_2103));


    Counter_v2_20_11 Wait_Counter (
        .reset(1'b0),
        .tc(Net_2148),
        .comp(Net_2149),
        .clock(Net_2114),
        .interrupt(Net_2146),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(1'b0));
    defparam Wait_Counter.CaptureMode = 0;
    defparam Wait_Counter.ClockMode = 3;
    defparam Wait_Counter.CompareMode = 1;
    defparam Wait_Counter.CompareStatusEdgeSense = 1;
    defparam Wait_Counter.EnableMode = 0;
    defparam Wait_Counter.ReloadOnCapture = 0;
    defparam Wait_Counter.ReloadOnCompare = 0;
    defparam Wait_Counter.ReloadOnOverUnder = 1;
    defparam Wait_Counter.ReloadOnReset = 1;
    defparam Wait_Counter.Resolution = 16;
    defparam Wait_Counter.RunMode = 1;
    defparam Wait_Counter.UseInterrupt = 1;


	cy_clock_v1_0
		#(.id("2a499dbc-e540-4ef6-835b-d791bc852cb1"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("10000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Wait_Clock
		 (.clock_out(Net_2114));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ISR_Wait
		 (.int_signal(Net_2146));


	wire [0:0] tmpOE__Pin_4_net;
	wire [0:0] tmpFB_0__Pin_4_net;
	wire [0:0] tmpIO_0__Pin_4_net;
	wire [0:0] tmpINTERRUPT_0__Pin_4_net;
	electrical [0:0] tmpSIOVREF__Pin_4_net;

	cy_psoc3_pins_v1_10
		#(.id("ba1b98fe-c8ea-4072-b50a-b7d27709277d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_sync(1'b1),
		  .intr_mode(2'b00),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .output_conn(1'b1),
		  .output_sync(1'b0),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Pin_4
		 (.oe(tmpOE__Pin_4_net),
		  .y({Net_1607}),
		  .fb({tmpFB_0__Pin_4_net[0:0]}),
		  .io({tmpIO_0__Pin_4_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_4_net),
		  .interrupt({tmpINTERRUPT_0__Pin_4_net[0:0]}));

	assign tmpOE__Pin_4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ADC_DelSig_v2_30_13 ADC_DelSig (
        .vplus(Net_1947),
        .vminus(Net_2205),
        .soc(1'b1),
        .eoc(Net_2207),
        .aclk(1'b0),
        .nVref(Net_2209));



endmodule

