# 1.下載Code Composer Studio
[Code Composer Studio下載點](https://www.ti.com/tool/CCSTUDIO#downloads)  
`本作者使用的Code Composer Studio版本為v11`

# 2. 下載C2000 ware  
[C2000 ware下載點](https://www.ti.com/tool/C2000WARE/)  
`請注意必須註冊帳號，完成註冊後才可申請下載，並在申請下載時勾選civil`  
![image](https://github.com/beibeiUUU/DSP28335/blob/main/Ti%20%E7%94%B3%E8%AB%8B%E4%B8%8B%E8%BC%89%E7%85%A7%E7%89%87-2%202024-06-14%2012_21_44.jpg)
- [x] civil

# 3. 建立工作環境
影片待補充

# 4.TMS320F28335 ePWM模組簡介
首先，TM2S320F28335的ePWM模組(Enhanced Pulse Width Modulator Module)和所有子模組連接，如`圖一`所示，每個ePWM模組代表一個完整的PWM通道，並且由兩個PWM輸出組成: EPWMxA、EPWMxB。而TMS320F28335內建了多組ePWM模組，如`圖二`所示，而在28335的使用手冊上指示，訊號或模組名稱中的字母 x 用於指示裝置上的通用 ePWM 模組。 例如，輸出訊號 EPWMxA 和 EPWMxB 指的是來自 ePWMx 實體的輸出訊號。因此，EPWM1A和EPWM1B同屬於ePWM1，同樣EPWM2A和EPWM2B同屬於ePWM2。並且設定好的PWM訊號將由General-Purpose Input/Output (GPIO) 輸出，如`圖三`所示。並且可以從`圖四`得知設定的PWM將由哪一隻腳輸出訊號。
![image](https://github.com/beibeiUUU/DSP28335/blob/main/TMS320F28335%E7%9A%84ePWM%E6%A8%A1%E7%B5%84%E5%92%8C%E6%89%80%E6%9C%89%E5%AD%90%E6%A8%A1%E7%B5%84%E9%80%A3%E6%8E%A5.png)  
上為圖一——ePWM模組和所有子模組連接  
![image](https://github.com/beibeiUUU/DSP28335/blob/main/TMS320F28335%E5%85%A7%E5%BB%BA%E5%A4%9A%E7%B5%84ePWM%E6%A8%A1%E7%B5%84.png)  
上為圖二——內建多組ePWM模組  
![image](https://github.com/beibeiUUU/DSP28335/blob/main/TMS320F28335%20GPIO%E8%BC%B8%E5%87%BA%E8%85%B3%E4%BD%8D%E5%9C%96.png)  
上為圖三——GPIO輸出腳位圖  
![image](https://github.com/beibeiUUU/DSP28335/blob/main/TMS320F28335%20GPIO%E8%BC%B8%E5%87%BA%E8%A8%AD%E5%AE%9A%E8%85%B3%E4%BD%8D%E5%9C%96.jpg)  
上為圖四——GPIO輸出設定腳位圖  

## TMS320F28335 ePWM的TimeBase Counter Synchronization子模組簡介  
Time-base synchronization scheme連接TMS320F28335上的所有 ePWM 模組。 每個 ePWM 模組都有一個同步輸入訊號 (EPWMxSYNCI) 和一個同步輸出訊號 (EPWMxSYNCO)。  
第一個 ePWM1模組的輸入同步訊號來自外部接腳。 其餘 ePWM 模組的同步連接如`圖五`所示
![image](https://github.com/beibeiUUU/DSP28335/blob/main/ePWM%20%E6%A8%A1%E7%B5%84%E7%9A%84%E5%90%8C%E6%AD%A5%E9%80%A3%E6%8E%A5%E5%9C%96.png)  
上為圖五——ePWM 模組的同步連接圖  

## TMS320F28335 ePWM的Action-Qualifier子模組簡介
會觸發ePWM的Action-Qualifier子模組所設定的動作。  
• Set High:  
   將輸出 EPWMxA 或 EPWMxB 設定為高電位。  
• Clear Low:  
   將輸出 EPWMxA 或 EPWMxB 設定為低電位。  
• Toggle:  
如果 EPWMxA 或 EPWMxB 目前輸出位於高電位，則將輸出切換為低電位。如果 EPWMxA 或 EPWMxB 目前輸出位於低電位，則將輸出切換為高電位。  
• Do Nothing:  
  將輸出 EPWMxA 和 EPWMxB 保持在與目前設定相同的電位。
  `圖六`表示了Action-Qualifier子模組在PWM波型上的動作圖示說明  
![image](https://github.com/beibeiUUU/DSP28335/blob/main/TMS320F28335%20AQ%E5%AD%90%E6%A8%A1%E7%B5%84%E5%9C%A8PWM%E6%B3%A2%E5%9E%8B%E4%B8%8A%E7%9A%84%E5%8B%95%E4%BD%9C%E5%9C%96%E7%A4%BA.png)  
上為圖六——ePWM 模組的同步連接圖  
## TMS320F28335 ePWM的Dead-Band Generator子模組簡介  
為了不讓IGBT同時導通，我們必須使用Dead-Band Generator子模組，啟動上升延遲delay to rising edges (RED) 和 下降延遲delay to falling edges (FED)。  
•Active high complementary (AHC): EPWMxB is inverted.  
•DBRED(Dead Band Rising Edge Delayed)  
•DBFED(Dead Band Falling Edge Delayed)  
![image](https://github.com/beibeiUUU/DSP28335/blob/main/TMS320F28335%20DeadBand%E5%AD%90%E6%A8%A1%E7%B5%84%E5%8F%AF%E7%94%A8%E7%9A%84%E6%A5%B5%E6%80%A7%E9%81%B8%E9%A0%85.png)  
上為圖七——DeadBand子模組可用的極性選項

# 5.計算的公式和作者設計程式時的想法

SYSCLKOUT = $\frac{主頻率}{2}$  
TBPRD(計數器上限) = $\frac{SYSCLKOUT}{目標頻率}$ = $\frac{75MHz}{21Khz}$ = 3571

![image](https://github.com/beibeiUUU/DSP28335/blob/main/dsp28335%20%E8%A8%AD%E5%AE%9A%E6%99%82%E7%9A%84%E6%83%B3%E6%B3%95.png)

# 6.參考資料
[tms320X2833X Technical Reference Manual](https://www.ti.com.cn/cn/lit/ug/sprui07/sprui07.pdf?ts=1710720155586#page=293&zoom=100,0,97)

# 7.
\forall
