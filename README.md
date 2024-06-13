# TMS320F28335 ePWM模組簡介
首先，TM2S320F28335的ePWM模組(Enhanced Pulse Width Modulator Module)和所有子模組連接，如`圖一`所示，每個ePWM模組代表一個完整的PWM通道，並且由兩個PWM輸出組成: EPWMxA、EPWMxB。而TMS320F28335內建了多組ePWM模組，如`圖二`所示，而在28335的使用手冊上指示，訊號或模組名稱中的字母 x 用於指示裝置上的通用 ePWM 模組。 例如，輸出訊號 EPWMxA 和 EPWMxB 指的是來自 ePWMx 實體的輸出訊號。因此，EPWM1A和EPWM1B同屬於ePWM1，同樣EPWM2A和EPWM2B同屬於ePWM2。並且設定好的PWM訊號將由General-Purpose Input/Output (GPIO) 輸出，如`圖三`所示。並且可以從圖四得知設定的PWM將由哪一隻腳輸出訊號。
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
第一個 ePWM1模組的輸入同步訊號來自外部接腳。 其餘 ePWM 模組的同步連接如圖五所示
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
  圖 2 5表示了Action-Qualifier子模組在PWM波型上的動作圖示說明
