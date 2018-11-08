#include "stdafx.h"
#include "VFrameBuffer.h"

void VFrameBuffer::Create(){
	if(m_hBmp){
		m_hBmp = (HBITMAP)::SelectObject(m_hMemDC, m_hBmp);
//		free(m_pOpBuffer);
		::DeleteObject(m_hBmp);
		::DeleteDC(m_hMemDC);	
	}



	

	m_hMemDC = ::CreateCompatibleDC(NULL);

	m_nBmpWidth = GetSystemMetrics(SM_CXSCREEN);
	m_nBmpHeight = GetSystemMetrics(SM_CYSCREEN);
#if 0
	BITMAPINFO bmf;
	memset(&bmf, 0, sizeof(bmf));
	bmf.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmf.bmiHeader.biBitCount = (WORD)m_bits;
	bmf.bmiHeader.biWidth = m_nBmpWidth;
	bmf.bmiHeader.biHeight = m_nBmpHeight;
	bmf.bmiHeader.biPlanes = 1;

#endif

	BITMAPV4HEADER bmf4;
	memset(&bmf4, 0, sizeof(bmf4));
	bmf4.bV4Size = sizeof(bmf4);
	bmf4.bV4BitCount = m_bits;
	bmf4.bV4Width = m_nBmpWidth;
	bmf4.bV4Height = m_nBmpHeight;
	bmf4.bV4Planes = 1;
	bmf4.bV4V4Compression = BI_BITFIELDS;

	bmf4.bV4RedMask = 0xf800;
	bmf4.bV4GreenMask = 0x07e0;
	bmf4.bV4BlueMask = 0x1f;

//	m_hBmp = CreateDIBSection(m_hMemDC, &bmf, DIB_RGB_COLORS,  (void**)&vBuffer, NULL, 0);

	m_hBmp = CreateDIBSection(m_hMemDC, (BITMAPINFO*)&bmf4, DIB_RGB_COLORS,  (void**)&vBuffer, NULL, 0);

	m_hBmp = (HBITMAP)::SelectObject(m_hMemDC, m_hBmp);

	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(141, 157, 143));
	//HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(240, 230, 140));
	RECT rt={0, 0, m_nBmpWidth, m_nBmpHeight};
	FillRect(m_hMemDC, &rt, hBrush);
	DeleteObject(hBrush);
}

VFrameBuffer::VFrameBuffer(int width, int height, int bits)
{
	m_hBmp = NULL;
	m_Width = width;
	m_Height = height;
	m_bits = bits;

	m_nBufSize = width * height * (bits / 8);
	m_pOpBuffer= (UINT*)malloc(m_nBufSize);

	Create();

	unsigned volatile short *pTemp = (unsigned short*)vBuffer;
}

void VFrameBuffer::OnScreen(HDC hScreenDC)
{
	OnScreen(hScreenDC, 0, 0);
}
void VFrameBuffer::OnScreen(HDC hScreenDC, int width, int height)
{
//	memcpy(vBuffer)
	int i, j;
	USHORT *p16Dest, *p16Src;
	UINT *p32Dest, *p32Src;

	p16Dest = (USHORT *)vBuffer;
	p16Src = (USHORT *)m_pOpBuffer;

	p32Dest = (UINT *)vBuffer;
	p32Src = (UINT *)m_pOpBuffer;

	if(width > m_nBmpWidth || height > m_nBmpHeight)
		Create();

	p16Dest += m_nBmpWidth * (m_nBmpHeight - 1 - 50) + 50;
	p32Dest += m_nBmpWidth * (m_nBmpHeight - 1 - 50) + 50;
#if 1
	for( i = 0; i < m_Height; i ++){
		for(j = 0; j < m_Width; j ++){
			if(m_bits == 32){
				p32Dest[j] = p32Src[j];
			}else if(m_bits == 16){
				p16Dest[j] = p16Src[j];
			}
		}
		if(m_bits == 32){
			p32Dest -= m_nBmpWidth;
			p32Src += m_Width;
		}else if(m_bits == 16){
			p16Dest -= m_nBmpWidth;
			p16Src += m_Width;
		}
	}
#endif
	if(width < 900)
		width = 900;
	::BitBlt(hScreenDC, 0, 0, m_nBmpWidth, m_nBmpHeight, m_hMemDC, 0, 0, SRCCOPY);
}
VFrameBuffer::~VFrameBuffer(void)
{
	m_hBmp = (HBITMAP)::SelectObject(m_hMemDC, m_hBmp);
	free(m_pOpBuffer);
	::DeleteObject(m_hBmp);
	::DeleteDC(m_hMemDC);
}
