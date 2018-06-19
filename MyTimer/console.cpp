#include "console.h"

char CRBTimer::Graphic::m_pArray[100];
list<UINT> CRBTimer::Graphic::record;

void CRBTimer::Graphic::Create()
{
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	//setbkcolor(DARKGRAY);

	rectangle(TITLE_LEFT, TITLE_TOP, SCREEN_WIDTH - TITLE_LEFT, TITLE_TOP + 100);

	LOGFONT f;
	gettextstyle(&f);
	settextcolor(LIGHTBLUE);

	f.lfHeight = 80;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式

	RECT r = { TITLE_LEFT, TITLE_TOP, SCREEN_WIDTH - TITLE_LEFT, TITLE_TOP + 100 };

	wsprintf((LPSTR)m_pArray, _T("计 时 器"));
	drawtext((LPSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	f.lfHeight = 36;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));  // 设置字体为“黑体”
	settextcolor(YELLOW);
	settextstyle(&f);                     // 设置字体样式

	r.top += 120;
	r.bottom = r.top + 120;

	wsprintf((LPSTR)m_pArray, _T("按【Enter/空格】开始/记录\n按【R】归零\n按【Esc】结束"));
	drawtext((LPSTR)m_pArray, &r, DT_CENTER | DT_VCENTER);
}

void CRBTimer::Graphic::Destroy()
{
	closegraph();
}

void CRBTimer::Graphic::AddRecord(std::chrono::milliseconds timeRecord)
{
	record.push_back(timeRecord.count());
	if (record.size() > 5)
		record.pop_front();
	CRBTimer::Graphic::DisplayRecord();
}

void CRBTimer::Graphic::DeleteRecord()
{
	record.clear();
	setfillcolor(BLACK);
	setcolor(BLACK);
	fillrectangle(RESULT_LEFT, RESULT_TOP, SCREEN_WIDTH - RESULT_LEFT, RESULT_TOP + 250);
}

void CRBTimer::Graphic::Display(MyTimer timer)
{
	UINT minutes, seconds, milliseconds;
	minutes = timer.GetTime().count();
	milliseconds = minutes % 1000u;
	seconds = (minutes /= 1000) % 60u;
	minutes = (minutes /= 60u) % 60u;

	RECT r = { TIME_LEFT, TIME_TOP, SCREEN_WIDTH - TIME_LEFT, TIME_TOP + 200 };

	LOGFONT f;
	gettextstyle(&f);
	settextcolor(WHITE);

	f.lfHeight = 160;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("宋体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式

	setbkcolor(BLACK);

	wsprintf((LPSTR)m_pArray, _T("%02d:%02d:%03d"), minutes, seconds, milliseconds);
	drawtext((LPSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top = RESULT_TOP;
	r.bottom = r.top + 50;


}

void CRBTimer::Graphic::DisplayRecord()
{
	if (!record.empty())
	{
		RECT r = { RESULT_LEFT, RESULT_TOP, SCREEN_WIDTH - RESULT_LEFT, RESULT_TOP + 50 };
		
		LOGFONT f;
		gettextstyle(&f);
		settextcolor(LIGHTRED);

		f.lfHeight = 40;                      // 设置字体高度为 48
		_tcscpy_s(f.lfFaceName, _T("宋体"));  // 设置字体为“黑体”
		f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
		settextstyle(&f);                     // 设置字体样式

		setbkcolor(BLACK);

		UINT minutes, seconds, milliseconds;
		for (auto &it : record) {
			UINT minutes, seconds, milliseconds;
			minutes = it;
			milliseconds = minutes % 1000u;
			seconds = (minutes /= 1000) % 60u;
			minutes = (minutes /= 60u) % 60u;

			wsprintf((LPSTR)m_pArray, _T("%02d:%02d:%03d"), minutes, seconds, milliseconds);
			drawtext((LPSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

			r.top += 50;
			r.bottom += 50;
		}
	}
}
