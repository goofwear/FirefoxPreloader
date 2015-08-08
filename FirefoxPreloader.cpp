/////////////////////////////////////////////////////////////////////////////
// Application Main - FirefoxPreloader.cpp
/////////////////////////////////////////////////////////////////////////////
// Copyright (C)2004 6XGate Incorporated
//
// This file is part of Firefox Preloader
//
// Firefox Preloader is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// Firefox Preloader is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Firefox Preloader; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
/////////////////////////////////////////////////////////////////////////////
// Defines the class behaviors for the application.
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FirefoxPreloader.h"
#include "DefaultDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFirefoxPreloaderApp

BEGIN_MESSAGE_MAP(CFirefoxPreloaderApp, CWinApp)
	//{{AFX_MSG_MAP(CFirefoxPreloaderApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirefoxPreloaderApp construction

CFirefoxPreloaderApp::CFirefoxPreloaderApp() {}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFirefoxPreloaderApp object

CFirefoxPreloaderApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFirefoxPreloaderApp initialization

BOOL CFirefoxPreloaderApp::InitInstance()
{
	::OutputDebugString(_T("\r\nStarting Firefox Preloader\r\n"));

	// Create and lock a mutex to detect existing instances
	CMutex mutex(TRUE, APP_MUTEX);
	if (!mutex.Lock(1000)) {
		CString szTitle; szTitle.LoadString(IDS_ERROR_TITLE);
		CString szMessage; szMessage.LoadString(IDS_EXISTING_INSTANCE);
		::MessageBox(NULL, szMessage, szTitle, MB_OK | MB_ICONINFORMATION );
		return FALSE;
	}

	Enable3dControls();				// Make controls appear 3D
	::InitializeProcessWatcher();	// Initialize the system specific process watching functions

	// Create the main INVISIBLE dialog that will receive all the messages and do all the work
	CDefaultDlg dlg;
	this->m_pMainWnd = &dlg;
	dlg.DoModal();

	// Deinitialize the process functions and unlock the mutex
	::OutputDebugString(_T("Ending Firefox Preloader\r\n"));
	::DeInitializeProcessWatcher();
	mutex.Unlock();

	// Since the dialog has been closed, return FALSE so that we exit the application, rather than start the application's message pump.
	return FALSE;
}
