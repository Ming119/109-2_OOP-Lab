# 國立臺北科技大學 2020 Spring 資工系物件導向程式實習

### 組員
+ 108590003 黃明萱
+ 108590050 李浩銘

## 簡介

### 動機
我們一開始也在想要做什麼，就先回想小時候玩過了哪一些遊戲，原本有找了類似冰火兄弟的雙人遊戲，但好像說過不能選這類型的遊戲就沒有選擇了，最後想到音速小子這款遊戲，對我們來說都是兒時回憶，也有達到老師的遊戲標準，所以就想玩自己寫出來的音速小子，來重現兒時回憶。

### 分工
李浩銘：主要遊戲程式的撰寫，除錯，以及封裝遊戲。  
黃明萱：尋找、處理與裁減素材、部分遊戲程式的撰寫。

## 遊戲介紹

### 遊戲說明

#### 遊戲操作
> 鍵盤上、下、左、右鍵控制角色方向的移動、空白建是跳躍。

#### 闖關模式
> 按照地圖跑到終點，會計時你花多久的時間，有金幣數量、分數。

#### 關卡陷阱
> 碰到怪物或踩到鋸齒都會game over，鋸齒會以三秒為一個循環出現。

#### 密技
> 鍵盤Q則可以隨意跑地圖。

### 遊戲圖形

### 遊戲音效
+ title.mp3	    - 遊戲進入選單畫面的音效  
+ options.mp3	- 進入選單option有不同的音效  
+ choose.wav	- 選單移動時的音效  
+ select.wav	- 選單確認時的音效  
+ return.wav	- Esc退出的音效  
+ crusader.mp3  - 每一關遊戲背景音效  
+ ring.wav	    - 遊戲裡吃金幣的音效  

## 程式設計

### 程式架構
我們把程式分成幾個主要的class，分別是Actor：角色、Bricks：方塊、Enemies：怪物、Items：物品、Level：關卡。

#### Actor
這個類別是角色的base-class，俱有angle角度、pos位置、velocity加速度、delta位移等主要變數，以及一個指向類別Bricks的指標refBrick。  
> 在OnInit階段，載入各種動作的圖檔，並且設定座標。
> 在OnMove階段，把delta位移計算出來，在3.3會詳述。  
> 在OnShow階段，根據玩家的操縱顯示各種動作。  

#### Brick
這個類別俱有id、angle角度、property屬性、behavior行為、texture材質、pos位置、delta位移等主要變數。  
> 在OnInit階段，會根據當前的關卡，以及object的id，自動取得texture材質、angle角度、property屬性以及behavior行為。  
> 在OnMove階段，會根據delta位移來進行移動。  
> 在OnShow階段，會把object的texture材質顯示出來。

#### Enemy
這個類別是怪物的base-class，俱有speed速度、direction方向、texture材質、spawn出生點、pos位置、delta位移等主要變數，以及一個指向類別Bricks的指標refBrick。共有17個derived-class。  
> 在OnInit階段，戴入相應的圖檔到texture材質，並且設定spawn出生點，根據spawn出生點找出refBrick，再根據refBrick微調spawn出生點。  
> 在OnMove階段，會根據delta位移來進行移動，然後再根據各個怪物的移動行為進行移動。  
> 在OnShow階段，會根據各個怪物的顯示行為把texture材質顯示出來。

#### Item
這個類別是物品的base-class，俱有id、texture材質、pos位置、delta位移等主要變數，以及一個指向類別Actor的指標currentActor。共有8個derived-class。  
> 在OnInit階段，戴入相應的圖檔到texture材質，並且設定座標。  
> 在OnMove階段，會根據delta位移來進行移動。  
> 在OnShow階段，會根據各個物品的顯示行為把texture材質顯示出來。

#### Level
這個類別是玩家與遊戲中各個object互動的橋樑，俱有rings戒指、score分數、delta位移等主要變數，並且有該關卡的Actor角色、所有Brick方塊、所有Item物品以及所有Enemy怪物的指標。  
> 在OnInit階段，根據所選擇的關卡，載入該關卡的Actor角色、Brick方塊、Item物品以及Enemy怪物。  
> 在OnMove階段，根據Actor的計算出來delta位移，控制Brick方塊、Item物品以及Enemy怪物進行移動。  
> 在OnShow階段，控制Brick方塊、Item物品以及Enemy怪物把texture材質顯示出來。  

### 程式類別
+ Actor	        - 角色的Base Class
+ Sonin	        - 角色1
+ Miles	        - 角色2 (Deprecated 棄用)
+ Knuckles      - 角色3 (Deprecated 棄用)
+ Brick	      	- 方塊
+ Enemy	      	- 敵人的Base Class
+ Bamboo	    - 敵人1
+ Chef		    - 敵人2
+ Earthworm	    - 敵人3
+ Fly		    - 敵人4
+ Groundhog   	- 敵人5
+ Insect	 	- 敵人6
+ Ladybug	    - 敵人7
+ Mosquito	    - 敵人8
+ Penguin	    - 敵人9
+ PinkMoster	- 敵人10
+ Rocket	 	- 敵人11
+ Shark	      	- 敵人12
+ Snails	    - 敵人13
+ Spider	    - 敵人14
+ Blue		    - 敵人15
+ FlyShield	    - 敵人16
+ Red			- 敵人17
+ Item		    - 物品的Base Class
+ Ring		    - 物品1
+ BIG_Ring	    - 物品2
+ GATE_YELLOW	- 物品3
+ SEND		    - 物品4
+ SPIKES_UP	    - 物品5
+ SPIKES_DOWN	- 物品6
+ SPIKES_LEFT	- 物品7
+ SPIKES_RIGHT  - 物品8
+ Level	      	- 關卡

### 程式技術
我們參考了原framework中提供的CInteger類別，加入了一個名為CString的類別(.h檔共20行，.cpp檔共120行)，用以顯示字串圖形，原因在4.1問題三中詳述。算法如下：
````c++
int nx = x;
int len = s.length();
for (int i = 0; i < len; i++) {
	if (s.at(i) == ' ') 	// Handling space
		nx += (int)(factor * alphabet[0].Width());

	else {
		int alphabet_num = int(s.at(i)) - int('A');	// Encode input alphabet ASCII to number 0~26
		if (isFocus()) 	// Handling focus, yellow alphabet
			alphabet_num += 26;

		alphabet[alphabet_num].SetTopLeft(nx, y);
		alphabet[alphabet_num].ShowBitmap();
		nx += (int)(factor * alphabet[alphabet_num].Width());
	}
}
````

角色的移動應該可以說是整個遊戲中最複雜的部分了，其分成四個階段：一檢查、二X軸移動，三Y軸移動，四計算delta位移。在一檢查階段，會檢查經過上一次的delta位移後，角色有沒有觸碰到怪物或陷阱。  

在二X軸移動階段，會計算X軸移動的acceleration加速度及velocity速度，這裡我們使用比較簡單的constant acceleration，設定acceleration為4，公式為v = u+at，轉換成程式碼即為velocity.x += acceleration，之後在加上friction摩擦力以及drag風阻作為減速，因為這裡涉及到比較複雜物理計算，因此我們把減速簡化成一個少於1的係數。  

在三Y軸移動階段，會計算Y軸移動的acceleration加速度及velocity速度，這裡我們使用自由落體的公式v = gt，轉換成程式碼即為velocity.y += gravity，因為我們簡化了friction摩擦力以及drag風阻，因此terminal velocity也簡化成一個常數。對於跳躍的部分，角色有一個jumpStrength，用於處理跳躍時velocity.y -= jumpStrength。  

在四計算delta位移階段，會根據階段二和階段三計算出來的的velocity，以以下的公式的計算出delta位移，level會取得這個delta位移，然後傳入各個Brick，Item，和Enemy，把角色delta位移的轉換成鏡頭的delta位移。  
> Δx = velovity.x∙cos⁡(angle) + velovity.y∙sin⁡(angle)  
> Δy = velovity.y∙cos⁡(angle) - velovity.x∙sin⁡(angle)  

## 結語

### 問題及解決方法
- 問題一：
>   原本遊戲內的背景是從右住左無限跑的動畫，並且分成不同的Layer，速度會有不一樣。
- 解決方法：
>	我們嘗試設定圖片跑到某個位置會重置，無果。最後放棄使用動畫，改成一張背景圖片。

- 問題二：
>	開源文件中只提供了各個物品、方塊、角色及怪物連續圖，但是framework卻要一張一張地載入。
- 解決方法：
>	也沒辦法只好一張一張把圖片剪出來，再放進遊戲中。

- 問題三：
>	開源文件中只提供了A~Z的字母圖片，我們須要想辨法把字母圖片組合成字串顯示出來。
- 解決方法：
>	我們想到2種方法，一是把字母圖片合併成我們想要顯示的字串。二是利用程式解決。我們選擇了後者，因為這樣的自由度更高，實作起來也比較快速。

- 問題四：
>	關於斜坡，基於這個Framework中的Bounding Box跟圖片的大小相同，我們沒辦法做出三角形的Bounding Box，讓人物跟著Bounding Box去移動。
- 解決方法：
>	在類別Bricks中加入變數angle，通過公式〖Δy=〖velovity〗_x∙tan〗⁡〖(angle)〗去計算出Y軸的相對移動距離Δy。
 
- 問題五：
>	承接上一個問題，關於180度迴轉，根據上述的計算方法，在變數angle等於90度時，Y軸的相對位移Δy理論上會等於無限。我們也有嘗試修改成原作者的計算方法，如下：  
>       Δx = velovity.x∙cos⁡(angle) + velovity.y∙sin⁡(angle)  
>       Δy = velovity.y∙cos⁡(angle) - velovity.x∙sin⁡(angle)  
>	修改計算方法後發現angle等於90度時，Y軸的相對位移Δy會等於0。最後發現是原作者的判斷方法跟我們的不一樣所導致的。
- 解決方法：
>	我們參考了原作者的判斷方法，嘗試進行修改。加角色身上加入一個判斷點，當0度時，判斷點在下方；當大於0度及小於90度，判斷點在右下方；當90度時，判斷點在右方；當大於90度及小於180度，判斷點在右上方；當180度時，判斷點在上方；當大於180度及小於270度，判斷點在左上方；當270度時，判斷點在左方；當大於270度及小於360度，判斷點在左下方。

- 問題六：
>	承接上一個問題，關於180度迴轉，這個判斷方法的確能夠通過部分180度迴轉。但是我們很快就發現了這個判斷方法並不完整，導致無汰通過所有180度迴轉。經過很長時間的思考，計算以及修改後，我們還是無法解決判斷方法不完整的問題。
- 解決方法：
>	最後我們自己寫了一個比較不好判斷方法，就是在180度迴轉的不同位置加入不同的透明點，角色在通過這幾個透明點的時候，會改變移動的角度。雖然這並非一個很好的解決方法，但是至少可以成功實作出來。

- 問題七：
> 	關於360度迴轉，我們發現在360度迴轉的時候，角色無法離開360度迴轉，原因是角色在碰到360度迴轉的最後一個透明點的下一個frame，又會再碰到360度迴轉的第一個透明點而再次進入360度迴轉，造成角色無法離開360度迴轉。
- 解決方法：
>	我們在第一個透明點上增加一點判斷，令角色再最後一個透明點回來時不會再次進入360度迴轉。

### 時間表

### 貢獻比例
+ 黃明萱：78小時，33.47%
+ 李浩銘：154小時，66.53%

### 自我檢核表
- [ ] 解決 Memory leak
- [x] 自定遊戲 Icon
- [x] 全螢幕啟動
- [x] 有 About 畫面
- [x] 初始畫面說明按鍵及滑鼠之用法與密技
- [x] 上傳 setup/apk/source 檔
- [x] setup 檔可正確執行
- [x] 報告字型、點數、對齊、行距、頁碼等格式正確

### 收獲
+ 黃明萱：
> 上學期在熟悉語法，這學期直接製作，這次程式使用了不少virtual function、Polymorphism、物理計算，讓我知道物理很重要，但好險可以google找到相關的物理公式，把所學到的知識全部結合在實作上面，能更加的了解程式的運作，也讓我知道除了程式碼以外，遊戲畫面裡的各種角色、地圖的構成、機關都是用圖片呈現出來的，所以處裡圖片也是相當花費時間，雖然我們有找到相關資源，但是裡面的圖片一張內有好幾個物件圖，必須把圖片一個一個進行裁剪，有些動畫分解圖，運用到CAnimation來呈現出更好的效果。除此之外也讓我更了解有些想要呈現的東西應該要寫在哪個區塊，怎麼寫判斷才會觸發到，不斷思考與隊員討論怎樣才會更好，讓遊戲呈現出我要的結果。

+ 李浩銘：
> 經過一個學期的實習後，我學到了不少東西，當中最主要的當然是了解了遊戲framework的運作，從整個遊戲的生命週期，以至於每一個stage的生命週期，老師提供的這個遊戲framework老師提供的這個framework都跟外面其他的framework大同小異。
在程式的文法上，我學到了一個新的東西叫Enum Class，因為我在撰寫程式碼的時候有用到幾個enum，但是有部分enum內的成員有重複，查了一下之後發現可以用Enum Class來解決。除此之外，這個學期的實習還讓我更深入地了解了物品導向，以及繼承等的觀念。
在除錯方式上，除了傳統的除錯方法，把變數打印出來，我還學到了如何使用除錯器。通過在程式碼中設定break point，可以暫停程式的運行，並查看記憶體空間等。

### 心得、感想
+ 黃明萱：
> 剛開始真的是很怕寫不出來，雖然上學期的課程有學到了C++程式語言的架構，但是有些地方真的還是會不清楚，也知道自己程式基礎沒有很好，而且更害怕拖累到隊友。剛開始的時候，比較簡單的東西隊友都先交給我像是程式裡的Item、Brick的 virtual function、Polymorphism，我覺得還行運用之前學得，但隨著東西越來越多，有些東西就只能與隊友討論或看有什麼解決方法，我們遇到最大的困難真的是那些角度，用了超多方法，都會穿牆，最後終於搞懂了。這次修物件導向程式設計實習課，讓我知道遊戲裡中的角色、物件、機關都很重要，定義方式也要很明確，當然最重要的是團隊合作的力量，我真的很感謝隊友因為常常我會自己卡住，所以我也從他身上學到很多。

+ 李浩銘：
> 我以前有寫過小遊戲的經驗，想說OOPL要寫遊戲，應該還好啦。結果選了一個讓自己很後悔的遊戲。一來是遊戲的東西很多，林林總總的方塊，物品，怪物。二來是framework的功能不太完整，比如圖片的旋轉跟反轉都沒有，讓我花了很多時間去研究到底要怎樣實作出來。寫到後面的時候，看到其他組的作品，發現我們的進度都比其他組落後，覺得自己有可能完成不了遊戲，很害怕被當掉。這個時候我還卡在角色迴轉，寫了兩個星期還是寫不出，真的感覺很迷茫，心很累，一度想放棄，但是我的組員把我從放棄的邊緣拉了回來，真的很感謝她。最後我們砍掉了很多功能，把迴轉硬幹出來，勉強地把遊戲完成了。

### 對於本課程的建議
+ Framework 增加旋轉圖片及反轉圖片功能。

## LICENSE
[GNU General Public License v3.0](https://github.com/Ming119/109-2_OOP-Lab/blob/main/LICENSE)
