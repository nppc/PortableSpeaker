EESchema Schematic File Version 4
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LED:WS2812B D1
U 1 1 5CB6FC3E
P 5000 3350
F 0 "D1" H 4800 3600 50  0000 L CNN
F 1 "WS2812B" H 5050 3600 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 5050 3050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 5100 2975 50  0001 L TNN
	1    5000 3350
	1    0    0    -1  
$EndComp
$Comp
L LED:WS2812B D2
U 1 1 5CB71BB8
P 5700 3350
F 0 "D2" H 5500 3600 50  0000 L CNN
F 1 "WS2812B" H 5750 3600 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 5750 3050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 5800 2975 50  0001 L TNN
	1    5700 3350
	1    0    0    -1  
$EndComp
$Comp
L LED:WS2812B D3
U 1 1 5CB725FB
P 6400 3350
F 0 "D3" H 6200 3600 50  0000 L CNN
F 1 "WS2812B" H 6450 3600 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 6450 3050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 6500 2975 50  0001 L TNN
	1    6400 3350
	1    0    0    -1  
$EndComp
$Comp
L LED:WS2812B D4
U 1 1 5CB72B01
P 7100 3350
F 0 "D4" H 6900 3600 50  0000 L CNN
F 1 "WS2812B" H 7150 3600 50  0000 L CNN
F 2 "LED_SMD:LED_WS2812B_PLCC4_5.0x5.0mm_P3.2mm" H 7150 3050 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf" H 7200 2975 50  0001 L TNN
	1    7100 3350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5CB73071
P 4350 3350
F 0 "J1" H 4268 3025 50  0000 C CNN
F 1 "IN" H 4268 3116 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4350 3350 50  0001 C CNN
F 3 "~" H 4350 3350 50  0001 C CNN
	1    4350 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	5000 3650 5700 3650
Wire Wire Line
	5700 3650 6400 3650
Connection ~ 5700 3650
Wire Wire Line
	6400 3650 7100 3650
Connection ~ 6400 3650
Wire Wire Line
	5000 3050 5700 3050
Wire Wire Line
	5700 3050 6400 3050
Connection ~ 5700 3050
Wire Wire Line
	6400 3050 7100 3050
Connection ~ 6400 3050
Wire Wire Line
	5300 3350 5400 3350
Wire Wire Line
	6000 3350 6100 3350
Wire Wire Line
	6700 3350 6800 3350
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5CB7660F
P 7900 3350
F 0 "J2" H 7818 3025 50  0000 C CNN
F 1 "OUT" H 7818 3116 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7900 3350 50  0001 C CNN
F 3 "~" H 7900 3350 50  0001 C CNN
	1    7900 3350
	1    0    0    1   
$EndComp
Wire Wire Line
	5000 3050 4550 3050
Wire Wire Line
	4550 3050 4550 3250
Connection ~ 5000 3050
Wire Wire Line
	4550 3450 4550 3650
Wire Wire Line
	4550 3650 5000 3650
Connection ~ 5000 3650
Wire Wire Line
	4550 3350 4700 3350
Wire Wire Line
	7100 3050 7700 3050
Wire Wire Line
	7700 3050 7700 3250
Connection ~ 7100 3050
Wire Wire Line
	7700 3450 7700 3650
Wire Wire Line
	7700 3650 7100 3650
Connection ~ 7100 3650
Wire Wire Line
	7400 3350 7700 3350
$EndSCHEMATC