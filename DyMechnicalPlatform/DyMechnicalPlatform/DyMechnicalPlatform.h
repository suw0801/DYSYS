// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DYMECHNICALPLATFORM_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DYMECHNICALPLATFORM_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DYMECHNICALPLATFORM_EXPORTS
#define DYMECHNICALPLATFORM_API __declspec(dllexport)
#else
#define DYMECHNICALPLATFORM_API __declspec(dllimport)
#endif

#include "DyMechicalAPI.h"

extern "C"
{
	//************************************
	// Method:    SysInit
	// FullName:  DyMechicalAPI::SysInit
	// Access:    public 
	// Returns:   bool
	// Qualifier: ϵͳ��ʼ��
	// Parameter: void
	//************************************
	DYMECHNICALPLATFORM_API bool API_SysInit(void);
	//************************************
	// Method:    SysQuit
	// FullName:  DyMechicalAPI::SysQuit
	// Access:    public 
	// Returns:   void
	// Qualifier: ϵͳ�ر�
	// Parameter: void
	//************************************
	DYMECHNICALPLATFORM_API void API_SysQuit(void);
	//************************************
	// Method:    FeedMotor_Start
	// FullName:  DyMechicalAPI::FeedMotor_Start
	// Access:    public 
	// Returns:   bool
	// Qualifier: ���ϵ������ת��
	// Parameter: void
	//************************************
	DYMECHNICALPLATFORM_API bool API_FeedMotor_Start(void);
	//************************************
	// Method:    FeedMotor_Stop
	// FullName:  DyMechicalAPI::FeedMotor_Stop
	// Access:    public 
	// Returns:   bool
	// Qualifier: ���ϵ��ֹͣת��
	// Parameter: void
	//************************************
	DYMECHNICALPLATFORM_API bool API_FeedMotor_Stop(void);
	//************************************
	// Method:    MotorStart
	// FullName:  DyMechicalAPI::MotorStart
	// Access:    public 
	// Returns:   bool
	// Qualifier: ָ������˶�
	// Parameter: int motorNum
	// Parameter: int direction
	// Parameter: int stepNum
	//************************************
	DYMECHNICALPLATFORM_API bool API_MotorStart(int motorNum,int direction,int stepNum);
	//************************************
	// Method:    MotorStop
	// FullName:  DyMechicalAPI::MotorStop
	// Access:    public 
	// Returns:   bool
	// Qualifier: ָ�����ֹͣ
	// Parameter: void
	//************************************
	DYMECHNICALPLATFORM_API bool API_MotorStop(int motorNum);
	//************************************
	// Method:    MotorReset
	// FullName:  DyMechicalAPI::MotorReset
	// Access:    public 
	// Returns:   bool
	// Qualifier: ָ�������λ
	// Parameter: int motorNum
	//************************************
	DYMECHNICALPLATFORM_API bool API_MotorReset(int motorNum);
	//************************************
	// Method:    SetMotorSpeed
	// FullName:  DyMechicalAPI::SetMotorSpeed
	// Access:    public 
	// Returns:   bool
	// Qualifier: ָ������ٶ�
	// Parameter: int motorNum
	//************************************
	DYMECHNICALPLATFORM_API bool API_SetMotorSpeed(int motorNum,int speed);
	//************************************
	// Method:    solenAction
	// FullName:  DyMechicalAPI::solenAction
	// Access:    public 
	// Returns:   bool
	// Qualifier: ָ����ŷ�����
	// Parameter: int solenNum
	// Parameter: int statue
	//************************************
	DYMECHNICALPLATFORM_API bool API_solenAction(int solenNum,int statue);
	//************************************
	// Method:    solenAdvace
	// FullName:  DyMechicalAPI::solenAdvace
	// Access:    public 
	// Returns:   bool
	// Qualifier: ָ������̨ȫ������
	// Parameter: int platformNum
	// Parameter: int statue
	//************************************
	DYMECHNICALPLATFORM_API bool API_solenAdvace(int platformNum,int statue);
	//************************************
	// Method:    getSolenStatue
	// FullName:  DyMechicalAPI::getSolenStatue
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ѯ�̵���״̬
	// Parameter: int * SolenStatue
	//************************************
	DYMECHNICALPLATFORM_API void API_getSolenStatue(int* SolenStatue);
	//************************************
	// Method:    getMotorStatue
	// FullName:  DyMechicalAPI::getMotorStatue
	// Access:    public 
	// Returns:   bool
	// Qualifier: ��ȡ����˶�״̬
	// Parameter: int * motorStatue
	//************************************
	DYMECHNICALPLATFORM_API bool API_getMotorStatue(int* motorStatue);
	//************************************
	// Method:    getPlatformStatue
	// FullName:  DyMechicalAPI::getPlatformStatue
	// Access:    public 
	// Returns:   bool
	// Qualifier: ��ѯָ������̨�������״̬
	// Parameter: int PlatformNum
	// Parameter: int * platformStatue
	//************************************
	DYMECHNICALPLATFORM_API bool API_getPlatformStatue(int PlatformNum,int platformStatue[8]);
	//************************************
	// Method:    API_getSensorStatue
	// FullName:  API_getSensorStatue
	// Access:    public 
	// Returns:   DYMECHNICALPLATFORM_API bool
	// Qualifier: ��ѯ������״̬
	// Parameter: int SensorStatue[8]
	//************************************
	DYMECHNICALPLATFORM_API bool API_getSensorStatue(int SensorStatue[8]);
	//************************************
	// Method:    API_getADSensor
	// FullName:  API_getADSensor
	// Access:    public 
	// Returns:   DYMECHNICALPLATFORM_API bool
	// Qualifier: ��ѯ������ADֵ
	// Parameter: double & value
	//************************************
	DYMECHNICALPLATFORM_API bool API_getADSensor(double& value);
	//************************************
	// Method:    API_RcvInit
	// FullName:  API_RcvInit
	// Access:    public 
	// Returns:   DYMECHNICALPLATFORM_API bool
	// Qualifier: ���ݽ��ճ�ʼ��
	// Parameter: void
	//************************************
	DYMECHNICALPLATFORM_API bool API_RcvInit(void);
};