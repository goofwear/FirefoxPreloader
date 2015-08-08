/////////////////////////////////////////////////////////////////////////////
// Helper functions external header - helpers.h
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

#if !defined(_HELPER_H__F3CC43CD_464D_471e_AE3A_CE9F4AFA3EAD__INCLUDED_)
#define _HELPER_H__F3CC43CD_464D_471e_AE3A_CE9F4AFA3EAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// External
extern "C" {

// Error messages
BOOL ErrorMessage(HWND hWndParent, LPCTSTR pszMessage, DWORD dwErrorCode);
BOOL GetLatestFirefoxInstallDir(CString *pszFirefoxPathBuffer);
BOOL GetCurrentFirefoxProfile(CString *pszProfilePathBuffer);
BOOL IsFileExists(LPCTSTR pszFilename);
UINT LoadAndWaitForFirefox(LPVOID pParam);

}

#endif // !defined(_HELPER_H__F3CC43CD_464D_471e_AE3A_CE9F4AFA3EAD__INCLUDED_)
