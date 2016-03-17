#pragma once


#import "c:\program files\common files\system\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
class DB
{
public:
	//Ĭ�ϳ�ʼ�����캯��
	DB(void);

	  //�������ӵĹ��캯��
	DB(_ConnectionPtr pConnection);
	//��������
	virtual~DB(void);

 public:

     //�������ݿ�
     BOOL Connect();
     
     //�ر����ݿ������
     void DisConnect();
     
     //���ݿ��ѯ��䣬���������ݿ�ĸ����ֶν��в�ѯ
     //����ɹ�����TRUE,���򷵻�FALSE.��ѯ�Ľ���洢����Ĺ��г�Ա����m_pRecordset��
     //��ѯ����������������ֱ𱣴��ڹ��г�Ա����m_nResultRow��m_nResultCol��
     BOOL Select(CString strSql);
     
     //��ѯ��䣬����Խ�����ѯһ���ֶε�������д���
     //��������CStringArray���͵ı���pResult��
     BOOL Select(CString strSql,CStringArray& Result);
     
     //�Զ���ֶν��в�ѯ
     BOOL SelectMulitCol(CString strSql,CStringArray& Result);
     
     //�򿪱�
     BOOL OpenTable(CString strTable);
     
     //�򿪱�
     BOOL OpenTable(CString strTable,CStringArray& Result);
     
     //���������ĸ��²���
     BOOL Execute(CString strSql);
 public:
     BOOL ExecuteTrans(CStringArray& aSql);    
     
     //�رս������
     void CloseRecordset();
     
     //�õ��������������
     long GetResultCol();
     
     //�õ��������������
     long GetResultRow();
     
     //�õ��������
     _RecordsetPtr GetResult();
 private:
     
     //���ݿ�������صĽ������
     long m_nResultRow;
     
     //���ص�_RecordsetPtr������
     long m_nResultCol;
     
     //����ָ��
     _ConnectionPtr m_pConnection;
     
     //����ִ��ָ��
     _CommandPtr m_pCommand;
     
     //�����ָ��
     _RecordsetPtr m_pRecordset;

};
