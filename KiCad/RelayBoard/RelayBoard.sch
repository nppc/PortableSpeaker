EESchema Schematic File Version 4
EELAYER 26 0
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
L Relay:IM45 K1
U 1 1 5CCDB137
P 3350 3150
F 0 "K1" H 3980 3196 50  0000 L CNN
F 1 "LY2NJ" H 3980 3105 50  0000 L CNN
F 2 "KiCadCustomLibs:Relay_LY2NJ" H 3150 3150 50  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=108-98001&DocType=SS&DocLang=EN" H 3150 3150 50  0001 C CNN
	1    3350 3150
	1    0    0    -1  
$EndComp
$Comp
L Relay:IM45 K2
U 1 1 5CCDB176
P 5950 3150
F 0 "K2" H 6580 3196 50  0000 L CNN
F 1 "LY2NJ" H 6580 3105 50  0000 L CNN
F 2 "KiCadCustomLibs:Relay_LY2NJ" H 5750 3150 50  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=108-98001&DocType=SS&DocLang=EN" H 5750 3150 50  0001 C CNN
	1    5950 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CCDB22C
P 2400 3450
F 0 "R1" V 2193 3450 50  0000 C CNN
F 1 "220" V 2284 3450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0414_L11.9mm_D4.5mm_P20.32mm_Horizontal" V 2330 3450 50  0001 C CNN
F 3 "~" H 2400 3450 50  0001 C CNN
	1    2400 3450
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5CCDB2F5
P 5000 3500
F 0 "R2" V 4793 3500 50  0000 C CNN
F 1 "220" V 4884 3500 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0414_L11.9mm_D4.5mm_P20.32mm_Horizontal" V 4930 3500 50  0001 C CNN
F 3 "~" H 5000 3500 50  0001 C CNN
	1    5000 3500
	0    1    1    0   
$EndComp
$Comp
L Device:CP C1
U 1 1 5CCDB34B
P 2400 3850
F 0 "C1" V 2655 3850 50  0000 C CNN
F 1 "100uF" V 2564 3850 50  0000 C CNN
F 2 "Capacitors_THT:CP_Radial_D8.0mm_P3.50mm" H 2438 3700 50  0001 C CNN
F 3 "~" H 2400 3850 50  0001 C CNN
	1    2400 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP C2
U 1 1 5CCDB3DF
P 5000 3900
F 0 "C2" V 5255 3900 50  0000 C CNN
F 1 "100uF" V 5164 3900 50  0000 C CNN
F 2 "Capacitors_THT:CP_Radial_D8.0mm_P3.50mm" H 5038 3750 50  0001 C CNN
F 3 "~" H 5000 3900 50  0001 C CNN
	1    5000 3900
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CCDB45C
P 4200 2600
F 0 "#PWR0101" H 4200 2350 50  0001 C CNN
F 1 "GND" H 4205 2427 50  0000 C CNN
F 2 "" H 4200 2600 50  0001 C CNN
F 3 "" H 4200 2600 50  0001 C CNN
	1    4200 2600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 5CCDB4A6
P 2100 3450
F 0 "#PWR0102" H 2100 3300 50  0001 C CNN
F 1 "VCC" H 2117 3623 50  0000 C CNN
F 2 "" H 2100 3450 50  0001 C CNN
F 3 "" H 2100 3450 50  0001 C CNN
	1    2100 3450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5CCDB605
P 1700 5000
F 0 "J2" H 1620 4675 50  0000 C CNN
F 1 "AMP2" H 1620 4766 50  0000 C CNN
F 2 "KiCadCustomLibs:Conn_Power" H 1700 5000 50  0001 C CNN
F 3 "~" H 1700 5000 50  0001 C CNN
	1    1700 5000
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5CCDB6E3
P 1700 4500
F 0 "J1" H 1620 4175 50  0000 C CNN
F 1 "AMP1" H 1620 4266 50  0000 C CNN
F 2 "KiCadCustomLibs:Conn_Power" H 1700 4500 50  0001 C CNN
F 3 "~" H 1700 4500 50  0001 C CNN
	1    1700 4500
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5CCDB73B
P 6200 1950
F 0 "J5" V 6166 2030 50  0000 L CNN
F 1 "BAT" V 6075 2030 50  0000 L CNN
F 2 "KiCadCustomLibs:Conn_Power" H 6200 1950 50  0001 C CNN
F 3 "~" H 6200 1950 50  0001 C CNN
	1    6200 1950
	0    1    -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5CCDB829
P 6150 4050
F 0 "J4" V 6023 4130 50  0000 L CNN
F 1 "CHG_OUT" V 6114 4130 50  0000 L CNN
F 2 "KiCadCustomLibs:Conn_Power" H 6150 4050 50  0001 C CNN
F 3 "~" H 6150 4050 50  0001 C CNN
	1    6150 4050
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J6
U 1 1 5CCDB86D
P 7600 5100
F 0 "J6" H 7519 4775 50  0000 C CNN
F 1 "CHG_IN" H 7519 4866 50  0000 C CNN
F 2 "KiCadCustomLibs:Conn_Power" H 7600 5100 50  0001 C CNN
F 3 "~" H 7600 5100 50  0001 C CNN
	1    7600 5100
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 5CCDB8E9
P 7650 3950
F 0 "J7" H 7569 3625 50  0000 C CNN
F 1 "V27" H 7569 3716 50  0000 C CNN
F 2 "KiCadCustomLibs:Conn_Power" H 7650 3950 50  0001 C CNN
F 3 "~" H 7650 3950 50  0001 C CNN
	1    7650 3950
	1    0    0    1   
$EndComp
Wire Wire Line
	1900 4500 2000 4500
Wire Wire Line
	2000 4500 2000 5000
Wire Wire Line
	2000 5000 1900 5000
Wire Wire Line
	1900 4900 2050 4900
Wire Wire Line
	2050 4900 2050 4400
Wire Wire Line
	2050 4400 1900 4400
Wire Wire Line
	2050 4900 2950 4900
Wire Wire Line
	2950 4900 2950 4250
Wire Wire Line
	2950 4250 3350 4250
Wire Wire Line
	3350 4250 3350 3450
Connection ~ 2050 4900
Wire Wire Line
	3750 3450 3750 4350
Wire Wire Line
	3750 4350 3050 4350
Wire Wire Line
	3050 4350 3050 5000
Wire Wire Line
	3050 5000 2000 5000
Connection ~ 2000 5000
$Comp
L power:VCC #PWR0103
U 1 1 5CCDBC65
P 7400 3700
F 0 "#PWR0103" H 7400 3550 50  0001 C CNN
F 1 "VCC" H 7417 3873 50  0000 C CNN
F 2 "" H 7400 3700 50  0001 C CNN
F 3 "" H 7400 3700 50  0001 C CNN
	1    7400 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5CCDBD6B
P 7400 4050
F 0 "#PWR0104" H 7400 3800 50  0001 C CNN
F 1 "GND" H 7405 3877 50  0000 C CNN
F 2 "" H 7400 4050 50  0001 C CNN
F 3 "" H 7400 4050 50  0001 C CNN
	1    7400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3950 7400 3950
Wire Wire Line
	7400 3950 7400 4050
Wire Wire Line
	7450 3850 7400 3850
Wire Wire Line
	7400 3850 7400 3700
Wire Wire Line
	3850 2850 3850 2600
Wire Wire Line
	3850 2600 4200 2600
$Comp
L power:GND #PWR0105
U 1 1 5CCDC1BC
P 7400 5200
F 0 "#PWR0105" H 7400 4950 50  0001 C CNN
F 1 "GND" H 7405 5027 50  0000 C CNN
F 2 "" H 7400 5200 50  0001 C CNN
F 3 "" H 7400 5200 50  0001 C CNN
	1    7400 5200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 5CCDC47B
P 7400 4750
F 0 "#PWR0106" H 7400 4600 50  0001 C CNN
F 1 "VCC" H 7417 4923 50  0000 C CNN
F 2 "" H 7400 4750 50  0001 C CNN
F 3 "" H 7400 4750 50  0001 C CNN
	1    7400 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4750 7400 5000
Wire Wire Line
	7400 5100 7400 5200
Wire Wire Line
	5950 3450 5950 3700
Wire Wire Line
	5950 3700 6050 3700
Wire Wire Line
	6050 3700 6050 3850
Wire Wire Line
	6150 3850 6150 3700
Wire Wire Line
	6150 3700 6350 3700
Wire Wire Line
	6350 3700 6350 3450
Wire Wire Line
	6200 2150 6200 2300
Wire Wire Line
	6200 2300 6450 2300
Wire Wire Line
	6450 2300 6450 2500
Wire Wire Line
	6050 2850 6050 2300
Wire Wire Line
	6050 2300 6100 2300
Wire Wire Line
	6100 2300 6100 2150
Wire Wire Line
	3650 2850 3650 2500
Wire Wire Line
	3650 2500 5400 2500
Connection ~ 6450 2500
Wire Wire Line
	6450 2500 6450 2850
Wire Wire Line
	3250 2850 3250 2300
Wire Wire Line
	3250 2300 5300 2300
Connection ~ 6050 2300
Wire Wire Line
	5150 3900 5550 3900
Wire Wire Line
	5550 3900 5550 3500
Wire Wire Line
	5150 3500 5550 3500
Connection ~ 5550 3500
Wire Wire Line
	5550 3500 5550 3450
Wire Wire Line
	4850 3500 4850 3900
Wire Wire Line
	2550 3450 2950 3450
Wire Wire Line
	2550 3850 2950 3850
Wire Wire Line
	2950 3850 2950 3450
Connection ~ 2950 3450
Wire Wire Line
	2250 3450 2250 3850
Wire Wire Line
	2100 3450 2250 3450
Connection ~ 2250 3450
$Comp
L power:GND #PWR0107
U 1 1 5CCE3363
P 2500 2850
F 0 "#PWR0107" H 2500 2600 50  0001 C CNN
F 1 "GND" H 2505 2677 50  0000 C CNN
F 2 "" H 2500 2850 50  0001 C CNN
F 3 "" H 2500 2850 50  0001 C CNN
	1    2500 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 2850 2950 2850
$Comp
L power:GND #PWR0108
U 1 1 5CCE3E1E
P 5100 2850
F 0 "#PWR0108" H 5100 2600 50  0001 C CNN
F 1 "GND" H 5105 2677 50  0000 C CNN
F 2 "" H 5100 2850 50  0001 C CNN
F 3 "" H 5100 2850 50  0001 C CNN
	1    5100 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2850 5550 2850
$Comp
L power:VCC #PWR0109
U 1 1 5CCE48FC
P 4650 3500
F 0 "#PWR0109" H 4650 3350 50  0001 C CNN
F 1 "VCC" H 4667 3673 50  0000 C CNN
F 2 "" H 4650 3500 50  0001 C CNN
F 3 "" H 4650 3500 50  0001 C CNN
	1    4650 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3500 4850 3500
Connection ~ 4850 3500
$Comp
L power:VCC #PWR0110
U 1 1 5CCE54AB
P 3450 2700
F 0 "#PWR0110" H 3450 2550 50  0001 C CNN
F 1 "VCC" H 3467 2873 50  0000 C CNN
F 2 "" H 3450 2700 50  0001 C CNN
F 3 "" H 3450 2700 50  0001 C CNN
	1    3450 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2700 3450 2850
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5CCE6084
P 5400 1950
F 0 "J3" V 5366 2030 50  0000 L CNN
F 1 "B_SENS" V 5275 2030 50  0000 L CNN
F 2 "KiCadCustomLibs:Conn_1x02_2.54mm" H 5400 1950 50  0001 C CNN
F 3 "~" H 5400 1950 50  0001 C CNN
	1    5400 1950
	0    1    -1   0   
$EndComp
Wire Wire Line
	5400 2150 5400 2500
Connection ~ 5400 2500
Wire Wire Line
	5400 2500 6450 2500
Wire Wire Line
	5300 2150 5300 2300
Connection ~ 5300 2300
Wire Wire Line
	5300 2300 6050 2300
$EndSCHEMATC
