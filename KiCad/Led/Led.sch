EESchema Schematic File Version 4
LIBS:Led-cache
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
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5CB7660F
P 5700 3350
F 0 "J2" H 5618 3025 50  0000 C CNN
F 1 "OUT" H 5618 3116 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5700 3350 50  0001 C CNN
F 3 "~" H 5700 3350 50  0001 C CNN
	1    5700 3350
	1    0    0    1   
$EndComp
Wire Wire Line
	5000 3050 4550 3050
Wire Wire Line
	4550 3050 4550 3250
Wire Wire Line
	4550 3450 4550 3650
Wire Wire Line
	4550 3650 5000 3650
Wire Wire Line
	4550 3350 4700 3350
Wire Wire Line
	5500 3050 5500 3250
Wire Wire Line
	5500 3450 5500 3650
Wire Wire Line
	5000 3050 5500 3050
Connection ~ 5000 3050
Wire Wire Line
	5000 3650 5500 3650
Connection ~ 5000 3650
Wire Wire Line
	5500 3350 5300 3350
$EndSCHEMATC
