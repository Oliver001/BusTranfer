#pragma once
#import "c:\program files\common files\system\ado\msado15.dll" \
	no_namespace \
	rename("EOF","adoEOF")
class ADO
{
public:
	ADO(void);
	~ADO(void);
	BOOL InitData(BSTR s);
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordset;
	bool Execute(BSTR SQL);
//	_RecordsetPtr Execute(CString SQL);
};
