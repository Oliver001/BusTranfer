#include "StdAfx.h"
#include "ADO.h"

ADO::ADO(void)
{
	::CoInitialize(NULL);

}

ADO::~ADO(void)
{
	::CoUninitialize();
}

BOOL ADO::InitData(BSTR s)
{
	HRESULT hr;
	try
	{
		hr=pConnection.CreateInstance(__uuidof(Connection));
		if (SUCCEEDED(hr))
		{
			pConnection->ConnectionString=_bstr_t(s);
			pConnection->ConnectionTimeout=10;
			hr=pConnection->Open("","","",adConnectUnspecified);

			if (FAILED(hr))
			{
				AfxMessageBox(_T("connect database fail"));
				return false;
			}
		} 
		else
		{
			AfxMessageBox(_T("Create instance of connection failed!"));
			return false;
		}

		hr=pRecordset.CreateInstance(__uuidof(Recordset));
		if (!SUCCEEDED(hr))
		{
			AfxMessageBox(_T("Create instance of Recordset failed!"));
			return false;
		}
	}
	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
		return false;
	}

	return true;
}
bool ADO::Execute(BSTR SQL)
{
	try
	{
		pRecordset=pConnection->Execute(SQL,NULL,-1);
	}

	catch (_com_error e)
	{
		_bstr_t bstrSource(e.Source()); 
		_bstr_t bstrDescription(e.Description());  
		AfxMessageBox(bstrSource + bstrDescription);  
		return false;
	}

	return true;
}
// 
// _RecordsetPtr ADO::Execute(CString SQL)
// {
// 	try
// 	{
// 		return pConnection->Execute(_bstr_t(SQL),NULL,adCmdText);
// 	}
// 
// 	catch(_com_error e)///捕捉异常
// 	{
// 		CString errormessage;
// 		errormessage.Format(_T("\n错误信息:%s"),e.ErrorMessage());
// 		AfxMessageBox(errormessage);///显示错误信息
// 	}
// 	return NULL;
// }
