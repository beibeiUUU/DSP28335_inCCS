# TMS320F28335 ePWM模組簡介
首先，TM2S320F28335的ePWM模組(Enhanced Pulse Width Modulator Module)和所有子模組連接，如圖X 所示，每個ePWM模組代表一個完整的PWM通道，並且由兩個PWM輸出組成: EPWMxA、EPWMxB。而TMS320F28335內建了多組ePWM模組，如圖 2 2所示，而在28335的使用手冊上指示，訊號或模組名稱中的字母 x 用於指示裝置上的通用 ePWM 模組。 例如，輸出訊號 EPWMxA 和 EPWMxB 指的是來自 ePWMx 實體的輸出訊號。   因此，EPWM1A和EPWM1B同屬於ePWM1，同樣EPWM2A和EPWM2B同屬於ePWM2。並且設定好的PWM訊號將由General-Purpose Input/Output (GPIO) 輸出，如圖 2 3所示。並且可以從表 2 1得知設定的PWM將由哪一隻腳輸出訊號。
![image](https://github.com/beibeiUUU/DSP28335/blob/main/TMS320F28335%E7%9A%84ePWM%E6%A8%A1%E7%B5%84%E5%92%8C%E6%89%80%E6%9C%89%E5%AD%90%E6%A8%A1%E7%B5%84%E9%80%A3%E6%8E%A5.png)  
圖一
