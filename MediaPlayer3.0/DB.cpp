#include "StdAfx.h"

#include "DB.h"

DB::DB(void)
{
	  //��ʼ��
     m_nResultRow = 0;
     m_nResultCol=0;
     m_pConnection = NULL;
     //��������
     m_pRecordset.CreateInstance(_uuidof(Recordset));
     m_pCommand.CreateInstance(_uuidof(Command));

}
DB::DB(_ConnectionPtr pConnection)
{
	 m_pConnection = pConnection; 
     m_nResultRow = 0;
     m_nResultCol=0;
     //��������
     m_pRecordset.CreateInstance(_uuidof(Recordset));
     m_pCommand.CreateInstance(_uuidof(Command)); 
}

DB::~DB(void)
{
	 if(m_pRecordset==NULL) return;
	 if(m_pRecordset->State!=adStateClosed)
     m_pRecordset->Close();
     m_pRecordset = NULL;
 
	 if(m_pCommand==NULL) return;
     if(m_pCommand->State!=adStateClosed)
         m_pCommand->Release();
     m_pCommand = NULL;
 
	 if(m_pConnection==NULL) return;
     if(m_pConnection->State!=adStateClosed) 
         m_pConnection->Close();
     m_pConnection = NULL; 
}


  /////////////////////////////////////////////////////////////////////
 ///�򵥲�������
 ////////////////////////////////////////////////////////////////////
 
 //�õ��������������
 long DB::GetResultRow()
  {
     return this->m_nResultRow;
 }
 
 //�õ��������������
 long DB::GetResultCol()
  {
     return this->m_nResultCol;
 }
 
 //�õ��������
 _RecordsetPtr DB::GetResult()
  {
     return this->m_pRecordset;
 }
 
  ///////////////////////////////////////////////////////////////////////
 ///���Ӳ���
 ///////////////////////////////////////////////////////////////////////
 
 //���ӵ����ݿ�
 //1.�����ַ��������Լ�����,Ҳ���Դ��ļ��ж���
 BOOL DB::Connect()
  {
      try{ 
         m_pConnection.CreateInstance(__uuidof(Connection));
         HRESULT hr;
 
		 hr=m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MediaPlayer.mdb","","",adModeUnknown); 
         //��������
         //����ʧ��
         if(FAILED(hr))
          {   
             AfxMessageBox("����ʧ��!");
             return FALSE;
         }
     }
     catch(_com_error&e)
      {
         AfxMessageBox(e.Description()+"B");
         return FALSE;
     } 
    return TRUE;
 }
 
 //�Ͽ�����
 void DB::DisConnect()
  {
	  if(m_pConnection==NULL)return;
     if(m_pConnection->State!=adStateClosed)
         m_pConnection->Close(); 
 }
 
  ///////////////////////////////////////////////////////////////////////
 ///���²���
 ///////////////////////////////////////////////////////////////////////
 BOOL DB::Execute(CString strSql)
  {
     try
      {
         _variant_t vNULL;
         vNULL.vt = VT_ERROR;
         
          ///����Ϊ�޲���
         vNULL.scode = DISP_E_PARAMNOTFOUND;
         
          ///�ǳ��ؼ���һ�䣬�����������Ӹ�ֵ����
         m_pCommand->ActiveConnection = m_pConnection;
         
          ///�����ִ�
         m_pCommand->CommandText = (_bstr_t)strSql;
         
          ///ִ�����ȡ�ü�¼��
         m_pRecordset = m_pCommand->Execute(&vNULL,&vNULL,adCmdText);
         
         //ȷʵ��vNULL�е�intVal��ִ�в�����Ӱ�������
         m_nResultRow = 0;
         m_nResultRow = vNULL.intVal;  
     }
     catch(_com_error&e)
      {
         m_nResultRow = 0;  
         return FALSE;
     }
     return TRUE;
 }
 
  ///////////////////////////////////////////////////////////////////////
 ///��ѯ����
 ///////////////////////////////////////////////////////////////////////
 BOOL DB::Select(CString strSql)
  {
     try
      {
         m_nResultCol=0;
         m_nResultRow=0;  
         m_pRecordset->CursorLocation=adUseClient;    //�����α�λ��,����Ϊ�ͻ�����ʽ,����GetRecordCount()����ֵ����
         m_pRecordset->Open(_variant_t(strSql),_variant_t((IDispatch *)m_pConnection,true),adOpenDynamic,adLockOptimistic,adCmdText);
         m_nResultCol = m_pRecordset->Fields->GetCount();//�õ���ѯ���������
         m_nResultRow = m_pRecordset->GetRecordCount();  //�õ���ѯ���������
     }
     catch(_com_error&e)
      {  
         AfxMessageBox(e.Description()+"D");
         return FALSE;
     }
     return TRUE;
 }
 
 //��ѯ��䣬����Խ�����ѯһ���ֶε�������д���
 //��������CStringArray���͵ı���pResult��
 BOOL DB::Select(CString strSql,CStringArray& Result)
  {
     if(Select(strSql)!=0)
      {
         Result.RemoveAll();
         for(int i=0;i<m_nResultRow;i++)
          {
             _variant_t value;
             value=m_pRecordset->Fields->Item[(long)0]->Value;   
             if(value.vt==3||value.vt==14)
              {
                 CString strTrans;
                 strTrans.Format("%ld",value.intVal);
                 Result.Add(strTrans);
             }
             else
				 {
                     CString strTrans(value.bstrVal);
					 Result.Add(strTrans);//
					 //Result.Add(value.bstrVal);//
				 }
                 //Result.Add((LPCTSTR)value.bstrVal);//cannot convert parameter 1 from 'BSTR' to 'LPCTSTR'
             m_pRecordset->MoveNext();
         }
         m_pRecordset->Close();
         return TRUE;
     }
     else
      {
         m_pRecordset->Close();
         return FALSE;
     }
 }
 
 //�Զ���ֶν��в�ѯ
 BOOL DB::SelectMulitCol(CString strSql,CStringArray& Result)
  {
     if(Select(strSql)!=0)
      {
         Result.RemoveAll();
         _variant_t value;
         for(int i=0;i<m_nResultRow;i++)
          {   
             for(int j=0;j<m_nResultCol;j++)
              {
                  value=m_pRecordset->Fields->Item[(long)(/*i*m_nResultCol+*/j)]->Value;
                 if(value.vt==3||value.vt==14)
                  {
                     CString strTrans;
                     strTrans.Format("%ld",value.intVal);
                     Result.Add(strTrans);
                 }
                 else
                     if(value.vt==7)
                      {
                         COleDateTime time = value.date;
                         CString strTemp;
                         strTemp.Format("%d-%d-%d %s",time.GetYear(),time.GetMonth(),time.GetDay(),time.Format("%H:%M:%S"));
                         Result.Add(strTemp);
                     }
                     else
					 {
                         CString strTrans(value.bstrVal);
						 Result.Add(strTrans);//
						 //Result.Add(value.bstrVal);//
					 }
             }
             m_pRecordset->MoveNext();
         }
         m_pRecordset->Close();
         return TRUE;
     }
     else
      { 
		  if(m_pRecordset==NULL)
			  return FALSE;
         m_pRecordset->Close();
         return FALSE;
     }
 }
 
 //�����ű�
 BOOL DB::OpenTable(CString strTable)
  {
     try
      {
         m_nResultCol=0;
         m_nResultRow=0;  
         m_pRecordset->CursorLocation=adUseClient;    //�����α�λ��,����Ϊ�ͻ�����ʽ,����GetRecordCount()����ֵ����
         m_pRecordset->Open(_variant_t(strTable),_variant_t((IDispatch *)m_pConnection,true),adOpenDynamic,adLockOptimistic,adCmdTable);
         m_nResultCol = m_pRecordset->Fields->GetCount();//�õ���ѯ���������
         m_nResultRow = m_pRecordset->GetRecordCount();  //�õ���ѯ���������
     }
     catch(_com_error&e)
      {  
         AfxMessageBox(e.Description()+"E");
         return FALSE;
     }
     return TRUE;
 }
 
 BOOL DB::OpenTable(CString strTable,CStringArray& Result)
  {
     if(OpenTable(strTable)!=0)
      {
         Result.RemoveAll();
         _variant_t value;
         for(int i=0;i<m_nResultRow;i++)
          {   
             for(int j=0;j<m_nResultCol;j++)
              {
                  value=m_pRecordset->Fields->Item[(long)(/*i*m_nResultCol+*/j)]->Value;
                 if(value.vt==3||value.vt==14)
                  {
                     CString strTrans;
                     strTrans.Format("%ld",value.intVal);
                     Result.Add(strTrans);
                 }
                 else
                     if(value.vt==7)
                      {
                         COleDateTime time = value.date;
                         CString strTemp;
                         strTemp.Format("%d-%d-%d %s",time.GetYear(),time.GetMonth(),time.GetDay(),time.Format("%H:%M:%S"));
                         Result.Add(strTemp);
                     }
                     else
                         Result.Add((LPCTSTR)value.bstrVal);//
             }
             m_pRecordset->MoveNext();
         }
         m_pRecordset->Close();
         return TRUE;
     }
     else
      {
         return FALSE;
     }
 }
 
  /////////////////////////////////////////////////////////////////////////////
 ///�رս����
 /////////////////////////////////////////////////////////////////////////////
 void DB::CloseRecordset()
  {
     if(m_pRecordset->State != adStateClosed)
         m_pRecordset->Close();
 }
 BOOL DB::ExecuteTrans(CStringArray& aSql)
  {
      try{
         int nNum = aSql.GetSize();
         m_pConnection->BeginTrans(); 
         for(int i=0;i<nNum;i++)
          {
             CString strSql = aSql.GetAt(i);  
             m_pConnection->Execute((_bstr_t)aSql.GetAt(i),NULL,adCmdText);
         }
         m_pConnection->CommitTrans(); 
         return TRUE;
     }
     catch(_com_error& e)
      {
         m_pConnection->RollbackTrans();  
         AfxMessageBox(e.Description()+"F");
         return FALSE;
     } 
 }
