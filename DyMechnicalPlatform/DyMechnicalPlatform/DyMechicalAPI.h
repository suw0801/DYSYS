#pragma once
#include "CnComm.h"
class DyMechicalAPI
{
public:
	DyMechicalAPI(void)
	{
		m_pCom=NULL;
		m_AD = 0;
		for (int i=0;i<48;i++)
			m_Solen[i]=0;
		for (int i=0;i<6;i++)
			m_motorStatue[i]=0;
		for (int i=0;i<8;i++)
		{
			m_platformStatue_IO1[i]=0;
			m_platformStatue_IO2[i]=0;
			m_platformStatue_IO3[i]=0;
			m_sensorStatue[i]=0;
		}	
	}

	~DyMechicalAPI(void)
	{

	}
private:
	//内部变量
	CnComm* m_pCom;
	int m_Solen[48];
	int m_motorStatue[6];
	int m_platformStatue_IO1[8];
	int m_platformStatue_IO2[8];
	int m_platformStatue_IO3[8];
	int m_sensorStatue[8];
	double m_AD;

private:
	//内部函数
	bool FindCard(CnComm* pCom)
	{
		for (int i=1;i<20;i++)
		{
			if (pCom->Open(i,57600))
			{
				unsigned char t_cmd[4];
				t_cmd[0]=0x55;
				t_cmd[1]=0x02;
				t_cmd[2]=0xbb;
				t_cmd[3]=0xaa;
				pCom->WritePort(t_cmd,4);
				Sleep(10);
				unsigned char t_Rcv[9];
				memset(t_Rcv,0,sizeof(unsigned char)*9);
				pCom->ReadPort(t_Rcv,9);
				if (t_Rcv[0]==0x48
					&&t_Rcv[1]==0x65
					&&t_Rcv[2]==0x6c
					&&t_Rcv[3]==0x6c
					&&t_Rcv[4]==0x6f
					&&t_Rcv[5]==0x4a
					&&t_Rcv[6]==0x49
					&&t_Rcv[7]==0x41
					&&t_Rcv[8]==0x21)
				{
					return true;
				}
			}
		}
		return false;
	}

public:
	//操作
	//************************************
	// Method:    SysInit
	// FullName:  DyMechicalAPI::SysInit
	// Access:    public 
	// Returns:   bool
	// Qualifier: 系统初始化
	// Parameter: void
	//************************************
	bool SysInit(void)
	{
		if (m_pCom!=NULL)
			return false;
		else
		{
			m_pCom=new CnComm;
			if (FindCard(m_pCom))
				return true;
			else
				return false;
		}
	}
	//************************************
	// Method:    SysQuit
	// FullName:  DyMechicalAPI::SysQuit
	// Access:    public 
	// Returns:   void
	// Qualifier: 系统关闭
	// Parameter: void
	//************************************
	void SysQuit(void)
	{
		m_pCom->Close();
		m_pCom=NULL;
		delete m_pCom;
	}
	//************************************
	// Method:    FeedMotor_Start
	// FullName:  DyMechicalAPI::FeedMotor_Start
	// Access:    public 
	// Returns:   bool
	// Qualifier: 进料电机持续转动
	// Parameter: void
	//************************************
	bool FeedMotor_Start(void)
	{
		if (m_pCom==NULL)
			return false;
		unsigned char t_cmd[4];
		t_cmd[0]=0x55;
		t_cmd[1]=0x02;
		t_cmd[2]=0xfb;
		t_cmd[3]=0xaa;
		m_pCom->Write(t_cmd,4);
		return true;
	}
	//************************************
	// Method:    FeedMotor_Stop
	// FullName:  DyMechicalAPI::FeedMotor_Stop
	// Access:    public 
	// Returns:   bool
	// Qualifier: 进料电机停止转动
	// Parameter: void
	//************************************
	bool FeedMotor_Stop(void)
	{
		if (m_pCom==NULL)
			return false;
		unsigned char t_cmd[4];
		t_cmd[0]=0x55;
		t_cmd[1]=0x02;
		t_cmd[2]=0xbf;
		t_cmd[3]=0xaa;
		m_pCom->Write(t_cmd,4);
		return true;
	}
	//************************************
	// Method:    MotorStart
	// FullName:  DyMechicalAPI::MotorStart
	// Access:    public 
	// Returns:   bool
	// Qualifier: 指定电机运动
	// Parameter: int motorNum
	// Parameter: int direction
	// Parameter: int stepNum
	//************************************
	bool MotorStart(int motorNum,int direction,int stepNum)
	{
		if (m_pCom==NULL)
			return false;
		if (motorNum<1||motorNum>6)
		{
			return false;
		}
		if (direction<0||direction>1)
		{
			return false;
		}
		unsigned char t_cmd[8];
		t_cmd[0]=0x55;
		t_cmd[1]=0x06;
		t_cmd[2]=0xfa;
		t_cmd[3]=motorNum;
		t_cmd[4]=direction;
		int t_highNum=0;
		int t_lowNum=0;
		t_highNum=stepNum/256;
		t_lowNum=stepNum%256;
		t_cmd[5]=t_highNum;
		t_cmd[6]=t_lowNum;
		t_cmd[7]=0xaa;
		m_pCom->Write(t_cmd,8);
		return true;
	}
	//************************************
	// Method:    MotorStop
	// FullName:  DyMechicalAPI::MotorStop
	// Access:    public 
	// Returns:   bool
	// Qualifier: 指定电机停止
	// Parameter: void
	//************************************
	bool MotorStop(int motorNum)
	{
		if (m_pCom==NULL)
			return false;
		if (motorNum<1||motorNum>6)
		{
			return false;
		}
		unsigned char t_cmd[5];
		t_cmd[0]=0x55;
		t_cmd[1]=0x03;
		t_cmd[2]=0xfd;
		t_cmd[3]=motorNum;
		t_cmd[4]=0xaa;
		m_pCom->Write(t_cmd,5);
		return true;
	}
	//************************************
	// Method:    MotorReset
	// FullName:  DyMechicalAPI::MotorReset
	// Access:    public 
	// Returns:   bool
	// Qualifier: 指定电机复位
	// Parameter: int motorNum
	//************************************
	bool MotorReset(int motorNum)
	{
		if (m_pCom==NULL)
			return false;
		if (motorNum<1||motorNum>6)
		{
			return false;
		}
		unsigned char t_cmd[5];
		t_cmd[0]=0x55;
		t_cmd[1]=0x03;
		t_cmd[2]=0xfc;
		t_cmd[3]=motorNum;
		t_cmd[4]=0xaa;
		m_pCom->Write(t_cmd,5);
		return true;
	}
	//************************************
	// Method:    SetMotorSpeed
	// FullName:  DyMechicalAPI::SetMotorSpeed
	// Access:    public 
	// Returns:   bool
	// Qualifier: 指定电机速度
	// Parameter: int motorNum
	//************************************
	bool SetMotorSpeed(int motorNum,int speed)
	{
		if (m_pCom==NULL)
			return false;
		if (motorNum<1||motorNum>6)
		{
			return false;
		}
		if (speed<0||speed>65535)
		{
			return false;
		}
		unsigned char t_cmd[7];
		t_cmd[0]=0x55;
		t_cmd[1]=0x05;
		t_cmd[2]=0xed;
		t_cmd[3]=motorNum;
		t_cmd[4]=speed/256;
		t_cmd[5]=speed%256;
		t_cmd[6]=0xaa;
		m_pCom->Write(t_cmd,7);
		return true;
	}
	//************************************
	// Method:    solenAction
	// FullName:  DyMechicalAPI::solenAction
	// Access:    public 
	// Returns:   bool
	// Qualifier: 指定电磁阀动作
	// Parameter: int solenNum
	// Parameter: int statue
	//************************************
	bool solenAction(int solenNum,int statue)
	{
		if (m_pCom==NULL)
			return false;
		if (solenNum<0||solenNum>47)
		{
			return false;
		}
		if (statue<0||statue>1)
		{
			return false;
		}
		unsigned char t_cmd[6];
		t_cmd[0]=0x55;
		t_cmd[1]=0x04;
		t_cmd[2]=0xfe;
		t_cmd[3]=solenNum;
		t_cmd[4]=statue;
		t_cmd[5]=0xaa;
		m_pCom->Write(t_cmd,6);
		//m_Solen[solenNum]=statue;
		return true;
	}
	//************************************
	// Method:    solenAdvace
	// FullName:  DyMechicalAPI::solenAdvace
	// Access:    public 
	// Returns:   bool
	// Qualifier: 指定工作台全部动作
	// Parameter: int platformNum
	// Parameter: int statue
	//************************************
	bool solenAdvace(int platformNum,int statue)
	{
		if (m_pCom==NULL)
			return false;
		if (platformNum<0||platformNum>2)
		{
			return false;
		}
		if (statue<0||statue>1)
		{
			return false;
		}
		unsigned char t_cmd[6];
		t_cmd[0]=0x55;
		t_cmd[1]=0x04;
		t_cmd[2]=0xef;
		t_cmd[3]=platformNum;
		t_cmd[4]=statue;
		t_cmd[5]=0xaa;
		m_pCom->Write(t_cmd,6);
		switch(platformNum)
		{
		case 0:
			for (int i=0;i<16;i++)
			{
				//m_Solen[i]=statue;
			}
			break;
		case 1:
			for (int i=16;i<32;i++)
			{
				//m_Solen[i]=statue;
			}
			break;
		case 2:
			for (int i=32;i<48;i++)
			{
				//m_Solen[i]=statue;
			}
			break;
		default:
			break;
		}
		return true;
	}
	
	//查询
	//************************************
	// Method:    getSolenStatue
	// FullName:  DyMechicalAPI::getSolenStatue
	// Access:    public 
	// Returns:   void
	// Qualifier: 查询继电器状态
	// Parameter: int * SolenStatue
	//************************************
	void getSolenStatue(int* SolenStatue)
	{
		CopyMemory(SolenStatue,m_Solen,sizeof(int)*6);
	}
	//************************************
	// Method:    getMotorStatue
	// FullName:  DyMechicalAPI::getMotorStatue
	// Access:    public 
	// Returns:   bool
	// Qualifier: 获取电机运动状态
	// Parameter: int * motorStatue
	//************************************
	bool getMotorStatue(int* motorStatue)
	{
		if (m_pCom==NULL)
			return false;
		
		CopyMemory(motorStatue,m_motorStatue,sizeof(int)*6);
		
		return true;
	}
	//************************************
	// Method:    getPlatformStatue
	// FullName:  DyMechicalAPI::getPlatformStatue
	// Access:    public 
	// Returns:   bool
	// Qualifier: 查询指定工作台的输入口状态
	// Parameter: int PlatformNum
	// Parameter: int * platformStatue
	//************************************
	bool getPlatformStatue(int PlatformNum,int* platformStatue)
	{
		if (m_pCom==NULL)
			return false;
		
		switch(PlatformNum)
		{
		case 0:
			{
				CopyMemory(platformStatue,m_platformStatue_IO1,sizeof(int)*8);
				break;
			}
		case 1:
			{
				CopyMemory(platformStatue,m_platformStatue_IO2,sizeof(int)*8);
				break;
			}
		case 2:
			{
				CopyMemory(platformStatue,m_platformStatue_IO3,sizeof(int)*8);
				break;
			}
		default:
				break;
		}
		
		return true;
	}

	//************************************
	// Method:    getSensorStatue
	// FullName:  DyMechicalAPI::getSensorStatue
	// Access:    public 
	// Returns:   bool
	// Qualifier: 获取IO量传感器IO值
	// Parameter: int * SensorStatue
	//************************************
	bool getSensorStatue(int* SensorStatue)
	{
		if (m_pCom==NULL)
			return false;
		
		CopyMemory(SensorStatue,m_sensorStatue,sizeof(int)*8);

		return true;
	}

	//************************************
	// Method:    GetADSensor
	// FullName:  DyMechicalAPI::GetADSensor
	// Access:    public 
	// Returns:   bool
	// Qualifier: 获取AD量传感器AD值
	// Parameter: double & value
	//************************************
	bool GetADSensor(double& value)
	{
		if (m_pCom==NULL)
			return false;

		value = m_AD;

		return true;
	}

	//************************************
	// Method:    rcvInit
	// FullName:  DyMechicalAPI::rcvInit
	// Access:    public 
	// Returns:   bool
	// Qualifier: 初始化数据接收
	// Parameter: void
	//************************************
	bool rcvInit(void)
	{
		if (m_pCom==NULL)
			return false;

		unsigned char t_cmd[4];
		t_cmd[0] = 0x55;
		t_cmd[1] = 0x02;
		t_cmd[2] = 0xf6;
		t_cmd[3] = 0xaa;
		m_pCom->Write(t_cmd,4);
		unsigned char t_rcv[16];
		m_pCom->Read(t_rcv,16);
		if (t_rcv[0] == 0x55
			&&t_rcv[1] == 0x0e
			&&t_rcv[15] == 0xaa){
				//AD
				m_AD = ((double)(t_rcv[2]*256+t_rcv[3]))*4096.0/3300.0;
				//Sensor Statue
				int t_Data_SensorStatue = 0;
				t_Data_SensorStatue = t_rcv[4];
				for (int i=0;i<8;i++)
					m_sensorStatue[i]=(t_Data_SensorStatue>>i)&0x01;
				//IO1|IO2|IO3
				int t_Data_IO1 = 0;
				int t_Data_IO2 = 0;
				int t_Data_IO3 = 0;
				t_Data_IO1 = t_rcv[5];
				t_Data_IO2 = t_rcv[6];
				t_Data_IO3 = t_rcv[7];
				for (int i=0;i<8;i++)
					m_platformStatue_IO1[i] = (t_Data_IO1>>i)&0x01;
				for (int i=0;i<8;i++)
					m_platformStatue_IO2[i] = (t_Data_IO2>>i)&0x01;
				for (int i=0;i<8;i++)
					m_platformStatue_IO3[i] = (t_Data_IO3>>i)&0x01;
				//Motor Statue
				int t_Data_MotorStatue = 0;
				t_Data_MotorStatue = t_rcv[8];
				for (int i=0;i<6;i++)
					m_motorStatue[i] = (t_Data_MotorStatue>>i)&0x01;
				//Solen Statue
				for (int i=0;i<8;i++){
					m_Solen[i] = (t_rcv[9]>>i)&0x01;
				}
				for(int i=8;i<16;i++){
					m_Solen[i] = (t_rcv[10]>>(i-8))&0x01;
				}
				for (int i=16;i<24;i++){
					m_Solen[i] = (t_rcv[11]>>(i-16))&0x01;
				}
				for (int i=24;i<32;i++){
					m_Solen[i] = (t_rcv[12]>>(i-24))&0x01;
				}
				for (int i=32;i<40;i++){
					m_Solen[i] = (t_rcv[13]>>(i-32))&0x01;
				}
				for (int i=40;i<48;i++){
					m_Solen[i] = (t_rcv[14]>>(i-40))&0x01;
				}
				
				return true;
		}
		else
			return false;
	}
};

