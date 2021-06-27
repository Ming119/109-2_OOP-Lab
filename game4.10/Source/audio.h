#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// 這個class會建立DirectX Audio物件，以提供音效
// 每個Public Interface的用法都要懂，Implementation可以不懂
// 注意事項：音效檔案可以用WAVE檔(.wav)或MIDI檔(.mid)，數個音效檔案可以
//           混合(同時)撥放，但是其中只能混合一個MIDI檔，兩個MIDI檔案不
//           能同時撥放，如果同時撥放兩個MIDI檔的話，前一個MIDI檔會被停
//           掉。
/////////////////////////////////////////////////////////////////////////////

namespace game_framework {

class CAudio {
public:
	~CAudio();
	void           Close();						// 關閉Direct Sound介面
	static CAudio* Instance();					// 取得CAudio的Instance
	bool           Load(unsigned, char *);		// 載入編號i的聲音，指定MIDI檔案
	bool           Open();						// 開啟Direct Sound介面
	void		   Pause();						// 暫停播放所有音效
	void           Play(unsigned, bool=false);	// 開始撥放編號i的聲音，指定是否重覆撥放
	void		   Resume();					// 復原暫停播放的音效
	void           SetPowerResume();			// 電源恢復
	void           Stop(unsigned);				// 停止撥放編號i的聲音

private:
	class Info {
	public:
		Info() {
			repeat = isGood = false;
		}
		bool repeat, isGood;
		string fileName;
	};
	static void MCIThread(HANDLE);	// MCI thread method
	static void ExecuteMciCommand(char *); // 
	void SendMciCommand(char *);	// 
	CAudio();						// private constructor
	static CAudio		audio;		// 自動destruct
	map<int, Info>		info;
	bool				isOpened;
    HANDLE				hThread;	// MCI command thread
	HANDLE				hWriteEnd;	// Pipe write handle for thread
	const static int	MAX_MCI_COMMAND_SIZE = 400;
};

}