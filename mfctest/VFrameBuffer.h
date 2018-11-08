#pragma once

class VFrameBuffer
{
protected:
	HDC m_hMemDC;
	HBITMAP m_hBmp;
	int m_Width, m_Height;
	int m_bits;

	int m_nBmpWidth, m_nBmpHeight;
public:

	UINT *vBuffer;
	UINT *m_pOpBuffer;
	int m_nBufSize;
	void Create();
	VFrameBuffer(int width, int height, int bits);
	void OnScreen(HDC hScreenDC);
	void OnScreen(HDC hScreenDC, int xpos, int ypos);
public:
	~VFrameBuffer(void);
};
