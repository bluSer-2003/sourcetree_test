#ifndef _STRUCT_H_
#define _STRUCT_H_

#define FUNACHIEVE_SYSCHOOSE	1             //该值为1时代表HIGHTEC环境      该值为2时代表TASKING环境
#define TRUE     	        1
#define FALSE                   0
#define ZERO                    0
#define ON                     	1
#define OFF                    	0

typedef float 					FWORD;
typedef unsigned long 				LWORD;
typedef volatile unsigned long 			VLWORD;
typedef unsigned short 				WORD;
typedef volatile unsigned short 		VWORD;
typedef unsigned char 				BYTE;
typedef volatile unsigned char 			VBYTE;


typedef volatile unsigned char  		ubyte;    // 1 byte unsigned; prefix: ub
typedef volatile signed char    		sbyte;    // 1 byte signed;   prefix: sb
typedef volatile unsigned short 		uword;   // 2 byte unsigned; prefix: uw
typedef volatile signed short   		sword;    // 2 byte signed;   prefix: sw
typedef volatile unsigned long  		ulong;    // 4 byte unsigned; prefix: ul
typedef volatile signed long    		slong;    // 4 byte signed;   prefix: sl
typedef volatile unsigned short 		ushort;   // 2 byte unsigned; prefix: us
typedef volatile signed short   		sshort;   // 2 byte signed;   prefix: ss
typedef volatile long long      		int64;    // 8 byte singed;
typedef volatile unsigned long long   	 	uint64;    // 8 byte unsinged;

typedef signed char          	sint8;          /*        -128 .. +127            */
typedef unsigned char        	uint8;          /*           0 .. 255             */
typedef signed short         	sint16;         /*      -32768 .. +32767          */
typedef unsigned short       	uint16;         /*           0 .. 65535           */
typedef signed long          	sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long        	uint32;         /*           0 .. 4294967295      */
typedef float                	float32;
typedef double               	float64;

typedef unsigned char       	boolean;        /* for use with TRUE/FALSE        */

#if   FUNACHIEVE_SYSCHOOSE == 1
typedef volatile unsigned char __bit;
#endif


#define   _inline     inline

union BYTE2
{ /* Declare a 2 byte union readable as byte, word */
	short  w;
	char  b[2];
};

union BYTE_F
{ /* Declare a 4 byte union - byte, word or lword */
	FWORD F;
	WORD w[2];
	BYTE b[4];
};

union BYTE4
{ /* Declare a 4 byte union - byte, word or lword */
	LWORD l;
	WORD w[2];
	BYTE b[4];
};

union BYTE8
{ /* Declare a 8 byte union - byte, word or lword */
	int64 ll;
	long  l[2];
	short   w[4];
	char   b[8];
};

union UBYTE8
{
	uint64 ll;
	ulong  l[2];
	ushort w[4];
	ubyte  b[8];
};

typedef volatile struct
{
  	unsigned char    bit0      : 1;
  	unsigned char    bit1      : 1;
  	unsigned char    bit2      : 1;
  	unsigned char    bit3      : 1;
  	unsigned char    bit4      : 1;
  	unsigned char    bit5      : 1;
  	unsigned char    bit6      : 1;
  	unsigned char    bit7      : 1;
}T_Reg8;


typedef volatile struct
{
	unsigned int    bit0      : 1;
	unsigned int    bit1      : 1;
	unsigned int    bit2      : 1;
	unsigned int    bit3      : 1;
	unsigned int    bit4      : 1;
	unsigned int    bit5      : 1;
	unsigned int    bit6      : 1;
	unsigned int    bit7      : 1;
	unsigned int    bit8      : 1;
	unsigned int    bit9      : 1;
	unsigned int    bit10     : 1;
	unsigned int    bit11     : 1;
	unsigned int    bit12     : 1;
	unsigned int    bit13     : 1;
	unsigned int    bit14     : 1;
	unsigned int    bit15     : 1;
}  T_Reg16;

typedef volatile struct
{
	unsigned int    bit0      : 1;
	unsigned int    bit1      : 1;
	unsigned int    bit2      : 1;
	unsigned int    bit3      : 1;
	unsigned int    bit4      : 1;
	unsigned int    bit5      : 1;
	unsigned int    bit6      : 1;
	unsigned int    bit7      : 1;
	unsigned int    bit8      : 1;
	unsigned int    bit9      : 1;
	unsigned int    bit10     : 1;
	unsigned int    bit11     : 1;
	unsigned int    bit12     : 1;
	unsigned int    bit13     : 1;
	unsigned int    bit14     : 1;
	unsigned int    bit15     : 1;
	unsigned int    bit16     : 1;
	unsigned int    bit17     : 1;
	unsigned int    bit18     : 1;
	unsigned int    bit19     : 1;
	unsigned int    bit20     : 1;
	unsigned int    bit21     : 1;
	unsigned int    bit22     : 1;
	unsigned int    bit23     : 1;
	unsigned int    bit24     : 1;
	unsigned int    bit25     : 1;
	unsigned int    bit26     : 1;
	unsigned int    bit27     : 1;
	unsigned int    bit28     : 1;
	unsigned int    bit29     : 1;
	unsigned int    bit30     : 1;
	unsigned int    bit31     : 1;
}T_Reg32;

typedef struct
{
	uint8 Mox;    		/* SW Handle that will identify the request in the confirmation callback function. */
	uint8 Active;           /* 接收数据的激活状态*/
	uint8 length;           /* DLC */
	uint32 id;            	/* Identifier of L-PDU */
	uint8 sdu[8];           /* Pointer to L-SDU */
}Can_ReceiveType;

typedef struct
{
	ubyte ubMOCfg;    // message object configuration
	ulong ulID;       // standard (11-bit)/extended (29-bit) identifier
	ulong ulMask;     // standard (11-bit)/extended (29-bit) mask
	ubyte ubData[8];  // 8-bit data bytes
	uword uwCounter;  // frame counter(MOIPRnH[15-0])
}stCAN_SWObj;

typedef struct
{
	ubyte Can_Nodenum;     	// 消息体的通道号
	ubyte msg_channel;     	// 消息体的通道号
	ubyte data_size;	//数据帧的大小
	ulong   Msg_Id;   	//消息体ID
	ubyte sendData[8];  	// 8-bit data bytes
}can_sendObj;

typedef struct
{
	float  Ea_valFrequency_C;       	//入口参数常量频率HZ
	float  Ea_valBenchmark_C;       	//入口参数常量分母基准
	float Ea_valCurrentVariable_MP;     	//入口参数变量

	float Ea_valBeforeVariable_LO;     	//中间过程量
	ubyte Ea_flgFirstCalculation_BP;   	//中间过程量

	float Ea_valChangeRate_MP;         	//最终结果，变量变化率
}EAf_VariableChangeRate;

typedef struct
{
	volatile union UBYTE8 CanBus_valRecCanData8;	//  Rec_CanData8
	uint8 CanBus_valDataLength;			//CanBus_DataLength

	ubyte  CanBus_flgRecActive  	:1;	//Rec_flgReceiveActive
	ubyte                        	:0;   	//填补区，不是真实变量,只占一个字节

}RecCan_valSeverDataNew;      //CAN数据接收接收数据的结构体   RecCan_SeverDataNew

#endif
