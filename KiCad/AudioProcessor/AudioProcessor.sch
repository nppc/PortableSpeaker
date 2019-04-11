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
L IC_Generic:IC28 U1
U 1 1 5CAB7CBC
P 5650 3350
F 0 "U1" H 5650 3950 50  0000 C CNN
F 1 "TDA7440" H 5650 3850 50  0000 C CNN
F 2 "Housings_SOIC:SOIC-28W_7.5x17.9mm_Pitch1.27mm" H 5650 3350 50  0001 C CNN
F 3 "" H 5650 3350 50  0001 C CNN
	1    5650 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0101
U 1 1 5CAB7E43
P 6500 3000
F 0 "#PWR0101" H 6500 2750 50  0001 C CNN
F 1 "GNDA" H 6505 2827 50  0000 C CNN
F 2 "" H 6500 3000 50  0001 C CNN
F 3 "" H 6500 3000 50  0001 C CNN
	1    6500 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CAB7E85
P 6350 4150
F 0 "#PWR0102" H 6350 3900 50  0001 C CNN
F 1 "GND" H 6355 3977 50  0000 C CNN
F 2 "" H 6350 4150 50  0001 C CNN
F 3 "" H 6350 4150 50  0001 C CNN
	1    6350 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5CAB7EA4
P 6800 3750
F 0 "C12" V 6750 3600 50  0000 L CNN
F 1 "5.6n" V 6650 3650 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 6838 3600 50  0001 C CNN
F 3 "~" H 6800 3750 50  0001 C CNN
	1    6800 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 3750 6650 3750
$Comp
L power:GNDA #PWR0103
U 1 1 5CAB7FDC
P 6950 3750
F 0 "#PWR0103" H 6950 3500 50  0001 C CNN
F 1 "GNDA" H 6955 3577 50  0000 C CNN
F 2 "" H 6950 3750 50  0001 C CNN
F 3 "" H 6950 3750 50  0001 C CNN
	1    6950 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5CAB802B
P 5450 4300
F 0 "C9" V 5600 4100 50  0000 L CNN
F 1 "100n" V 5600 4250 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 5488 4150 50  0001 C CNN
F 3 "~" H 5450 4300 50  0001 C CNN
	1    5450 4300
	0    1    1    0   
$EndComp
$Comp
L Device:C C10
U 1 1 5CAB815A
P 5850 4300
F 0 "C10" V 6000 4100 50  0000 L CNN
F 1 "100n" V 6000 4250 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 5888 4150 50  0001 C CNN
F 3 "~" H 5850 4300 50  0001 C CNN
	1    5850 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	5300 4050 5300 4300
Wire Wire Line
	6000 4050 6000 4300
Wire Wire Line
	5700 4300 5650 4300
Wire Wire Line
	5650 4300 5650 4500
Connection ~ 5650 4300
Wire Wire Line
	5650 4300 5600 4300
$Comp
L Device:R R10
U 1 1 5CAB8313
P 5650 4650
F 0 "R10" H 5720 4696 50  0000 L CNN
F 1 "5.6k" H 5720 4605 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" V 5580 4650 50  0001 C CNN
F 3 "~" H 5650 4650 50  0001 C CNN
	1    5650 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0104
U 1 1 5CAB83E5
P 5650 4800
F 0 "#PWR0104" H 5650 4550 50  0001 C CNN
F 1 "GNDA" H 5655 4627 50  0000 C CNN
F 2 "" H 5650 4800 50  0001 C CNN
F 3 "" H 5650 4800 50  0001 C CNN
	1    5650 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5CAB8434
P 4800 3900
F 0 "C7" V 4850 3700 50  0000 L CNN
F 1 "2.2uf" V 4750 3650 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 4838 3750 50  0001 C CNN
F 3 "~" H 4800 3900 50  0001 C CNN
	1    4800 3900
	0    1    1    0   
$EndComp
$Comp
L Device:C C11
U 1 1 5CAB8700
P 6800 3450
F 0 "C11" V 6750 3300 50  0000 L CNN
F 1 "5.6n" V 6650 3350 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 6838 3300 50  0001 C CNN
F 3 "~" H 6800 3450 50  0001 C CNN
	1    6800 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	6950 3450 6950 3750
Connection ~ 6950 3750
Wire Wire Line
	6650 3450 6650 3650
Wire Wire Line
	6650 3650 6000 3650
$Comp
L Device:C C5
U 1 1 5CAB8D2F
P 4650 4300
F 0 "C5" V 4800 4100 50  0000 L CNN
F 1 "100n" V 4800 4250 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 4688 4150 50  0001 C CNN
F 3 "~" H 4650 4300 50  0001 C CNN
	1    4650 4300
	0    1    1    0   
$EndComp
$Comp
L Device:C C8
U 1 1 5CAB8D36
P 5050 4300
F 0 "C8" V 5200 4100 50  0000 L CNN
F 1 "100n" V 5200 4250 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 5088 4150 50  0001 C CNN
F 3 "~" H 5050 4300 50  0001 C CNN
	1    5050 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 4050 4500 4300
Wire Wire Line
	4900 4300 4850 4300
Wire Wire Line
	4850 4300 4850 4500
Connection ~ 4850 4300
Wire Wire Line
	4850 4300 4800 4300
$Comp
L Device:R R9
U 1 1 5CAB8D43
P 4850 4650
F 0 "R9" H 4920 4696 50  0000 L CNN
F 1 "5.6k" H 4920 4605 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" V 4780 4650 50  0001 C CNN
F 3 "~" H 4850 4650 50  0001 C CNN
	1    4850 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0105
U 1 1 5CAB8D4A
P 4850 4800
F 0 "#PWR0105" H 4850 4550 50  0001 C CNN
F 1 "GNDA" H 4855 4627 50  0000 C CNN
F 2 "" H 4850 4800 50  0001 C CNN
F 3 "" H 4850 4800 50  0001 C CNN
	1    4850 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 4050 5100 4050
Wire Wire Line
	5100 4050 5100 3850
Wire Wire Line
	5100 3850 5300 3850
Wire Wire Line
	5200 3950 5300 3950
Wire Wire Line
	5200 3950 5200 4300
$Comp
L Device:C C13
U 1 1 5CAB99E3
P 7100 3250
F 0 "C13" V 6950 3150 50  0000 L CNN
F 1 "2.2uf" V 7250 3150 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 7138 3100 50  0001 C CNN
F 3 "~" H 7100 3250 50  0001 C CNN
	1    7100 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 3250 6950 3250
Wire Wire Line
	7250 3250 7250 3750
Wire Wire Line
	7250 3750 6950 3750
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 5CABA6A9
P 7200 2350
F 0 "J7" H 7280 2342 50  0000 L CNN
F 1 "LOUT" H 7280 2251 50  0000 L CNN
F 2 "KiCadCustomLibs:Conn2pin_2.54mm" H 7200 2350 50  0001 C CNN
F 3 "~" H 7200 2350 50  0001 C CNN
	1    7200 2350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J8
U 1 1 5CABA736
P 7200 2600
F 0 "J8" H 7280 2592 50  0000 L CNN
F 1 "ROUT" H 7280 2501 50  0000 L CNN
F 2 "KiCadCustomLibs:Conn2pin_2.54mm" H 7200 2600 50  0001 C CNN
F 3 "~" H 7200 2600 50  0001 C CNN
	1    7200 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2950 6750 2950
Wire Wire Line
	6750 2950 6750 2600
Wire Wire Line
	6750 2600 7000 2600
Wire Wire Line
	6000 2850 6700 2850
Wire Wire Line
	6700 2850 6700 2350
Wire Wire Line
	6700 2350 7000 2350
Wire Wire Line
	7000 2450 6900 2450
Wire Wire Line
	6900 2450 6900 2700
Wire Wire Line
	6900 2700 7000 2700
$Comp
L power:GNDA #PWR0106
U 1 1 5CABBBC6
P 6900 2700
F 0 "#PWR0106" H 6900 2450 50  0001 C CNN
F 1 "GNDA" H 6905 2527 50  0000 C CNN
F 2 "" H 6900 2700 50  0001 C CNN
F 3 "" H 6900 2700 50  0001 C CNN
	1    6900 2700
	1    0    0    -1  
$EndComp
Connection ~ 6900 2700
$Comp
L power:+9V #PWR0107
U 1 1 5CABBE17
P 6200 3150
F 0 "#PWR0107" H 6200 3000 50  0001 C CNN
F 1 "+9V" H 6300 3200 50  0000 C CNN
F 2 "" H 6200 3150 50  0001 C CNN
F 3 "" H 6200 3150 50  0001 C CNN
	1    6200 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3150 6200 3150
Wire Wire Line
	6150 3050 6150 3000
Wire Wire Line
	6150 3000 6500 3000
Wire Wire Line
	6000 3050 6150 3050
$Comp
L Connector_Generic:Conn_01x03 J6
U 1 1 5CABD2A1
P 6350 3450
F 0 "J6" H 6450 3600 50  0000 L CNN
F 1 "I2C" H 6450 3500 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 6350 3450 50  0001 C CNN
F 3 "~" H 6350 3450 50  0001 C CNN
	1    6350 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3350 6150 3350
Text Label 6000 3350 0    50   ~ 0
SDA
Wire Wire Line
	6000 3450 6150 3450
Text Label 6000 3450 0    50   ~ 0
SCL
Wire Wire Line
	6000 3550 6150 3550
Text Label 6000 3550 0    50   ~ 0
GND
NoConn ~ 6000 3850
NoConn ~ 6000 3950
Text Label 6000 2950 0    50   ~ 0
ROUT
Text Label 6000 2850 0    50   ~ 0
LOUT
$Comp
L Device:R R4
U 1 1 5CAC3CFC
P 4450 2950
F 0 "R4" V 4400 2800 50  0000 C CNN
F 1 "600" V 4450 2950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 2950 50  0001 C CNN
F 3 "~" H 4450 2950 50  0001 C CNN
	1    4450 2950
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5CAC3EEF
P 4450 3050
F 0 "R5" V 4400 2900 50  0000 C CNN
F 1 "600" V 4450 3050 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 3050 50  0001 C CNN
F 3 "~" H 4450 3050 50  0001 C CNN
	1    4450 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 2950 5300 2950
Wire Wire Line
	4600 3050 5300 3050
Wire Wire Line
	4300 2950 4200 2950
Wire Wire Line
	4200 2950 4200 3000
Wire Wire Line
	4200 3050 4300 3050
$Comp
L Device:C C4
U 1 1 5CAC669D
P 4050 3000
F 0 "C4" V 4000 2850 50  0000 L CNN
F 1 "2.2uf" V 4250 2900 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 4088 2850 50  0001 C CNN
F 3 "~" H 4050 3000 50  0001 C CNN
	1    4050 3000
	0    1    1    0   
$EndComp
Connection ~ 4200 3000
Wire Wire Line
	4200 3000 4200 3050
$Comp
L Device:R R3
U 1 1 5CAC693F
P 4450 2850
F 0 "R3" V 4400 2700 50  0000 C CNN
F 1 "600" V 4450 2850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 2850 50  0001 C CNN
F 3 "~" H 4450 2850 50  0001 C CNN
	1    4450 2850
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5CAC6975
P 4450 3150
F 0 "R6" V 4400 3000 50  0000 C CNN
F 1 "600" V 4450 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 3150 50  0001 C CNN
F 3 "~" H 4450 3150 50  0001 C CNN
	1    4450 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 2850 5300 2850
Wire Wire Line
	4600 3150 5300 3150
Wire Wire Line
	4300 3150 3800 3150
Wire Wire Line
	3800 3150 3800 2850
Wire Wire Line
	3800 2850 4300 2850
$Comp
L Device:C C3
U 1 1 5CAC9D2E
P 3650 3150
F 0 "C3" V 3600 3000 50  0000 L CNN
F 1 "2.2uf" V 3500 3050 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 3688 3000 50  0001 C CNN
F 3 "~" H 3650 3150 50  0001 C CNN
	1    3650 3150
	0    1    1    0   
$EndComp
Connection ~ 3800 3150
Wire Wire Line
	3900 3000 3850 3000
Wire Wire Line
	3850 3000 3850 2300
Text Label 3850 2300 3    50   ~ 0
IN1
Wire Wire Line
	3500 3150 3450 3150
Wire Wire Line
	3450 3150 3450 2300
Text Label 3450 2300 3    50   ~ 0
IN2
$Comp
L Device:R R7
U 1 1 5CACF5FA
P 4450 3250
F 0 "R7" V 4400 3100 50  0000 C CNN
F 1 "600" V 4450 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 3250 50  0001 C CNN
F 3 "~" H 4450 3250 50  0001 C CNN
	1    4450 3250
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5CACF63A
P 4450 2750
F 0 "R2" V 4400 2600 50  0000 C CNN
F 1 "600" V 4450 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 2750 50  0001 C CNN
F 3 "~" H 4450 2750 50  0001 C CNN
	1    4450 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 2750 5300 2750
Wire Wire Line
	5300 3250 4600 3250
Wire Wire Line
	5050 3750 5300 3750
Wire Wire Line
	5050 3750 5050 3900
Wire Wire Line
	5050 3900 4950 3900
Wire Wire Line
	5300 3650 5000 3650
Wire Wire Line
	5000 3650 5000 3800
Wire Wire Line
	5000 3800 4500 3800
Wire Wire Line
	4650 3900 4500 3900
Wire Wire Line
	4500 3900 4500 3800
Connection ~ 4500 3800
Wire Wire Line
	4500 3800 4300 3800
$Comp
L Device:C C6
U 1 1 5CADAC66
P 4800 3700
F 0 "C6" V 4850 3500 50  0000 L CNN
F 1 "2.2uf" V 4750 3450 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 4838 3550 50  0001 C CNN
F 3 "~" H 4800 3700 50  0001 C CNN
	1    4800 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 3700 4950 3550
Wire Wire Line
	4950 3550 5300 3550
Wire Wire Line
	5300 3450 4900 3450
Wire Wire Line
	4900 3450 4900 3600
Wire Wire Line
	4900 3600 4500 3600
Wire Wire Line
	4650 3700 4500 3700
Wire Wire Line
	4500 3700 4500 3600
Connection ~ 4500 3600
Wire Wire Line
	4500 3600 4300 3600
$Comp
L Device:C C2
U 1 1 5CADF4EE
P 3250 2750
F 0 "C2" V 3200 2600 50  0000 L CNN
F 1 "2.2uf" V 3400 2650 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 3288 2600 50  0001 C CNN
F 3 "~" H 3250 2750 50  0001 C CNN
	1    3250 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	4300 2750 3400 2750
Wire Wire Line
	4300 3250 3400 3250
Wire Wire Line
	3400 3250 3400 2750
Connection ~ 3400 2750
Wire Wire Line
	3100 2750 3100 2300
Text Label 3100 2300 3    50   ~ 0
IN3
$Comp
L Device:R R8
U 1 1 5CAE4ED4
P 4450 3350
F 0 "R8" V 4400 3200 50  0000 C CNN
F 1 "600" V 4450 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 3350 50  0001 C CNN
F 3 "~" H 4450 3350 50  0001 C CNN
	1    4450 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5CAE4F16
P 4450 2650
F 0 "R1" V 4400 2500 50  0000 C CNN
F 1 "600" V 4450 2650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4380 2650 50  0001 C CNN
F 3 "~" H 4450 2650 50  0001 C CNN
	1    4450 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 3350 5300 3350
Wire Wire Line
	4600 2650 6000 2650
Wire Wire Line
	6000 2650 6000 2750
Wire Wire Line
	4300 2650 2950 2650
Wire Wire Line
	2950 2650 2950 2950
Wire Wire Line
	2950 3350 4300 3350
$Comp
L Device:C C1
U 1 1 5CAEB3C5
P 2800 2950
F 0 "C1" V 2750 2800 50  0000 L CNN
F 1 "2.2uf" V 2950 2850 50  0000 L CNN
F 2 "Capacitors_THT:C_Rect_L7.0mm_W2.0mm_P5.00mm" H 2838 2800 50  0001 C CNN
F 3 "~" H 2800 2950 50  0001 C CNN
	1    2800 2950
	0    1    1    0   
$EndComp
Connection ~ 2950 2950
Wire Wire Line
	2950 2950 2950 3350
Wire Wire Line
	2650 2950 2650 2300
Text Label 2650 2300 3    50   ~ 0
IN4
Wire Wire Line
	6350 4150 6350 4000
Text Label 6350 4000 3    50   ~ 0
GND
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5CAF069D
P 2650 2100
F 0 "J1" V 2850 2100 50  0000 R CNN
F 1 "IN4" V 2750 2100 50  0000 R CNN
F 2 "KiCadCustomLibs:Conn2pin_2.54mm" H 2650 2100 50  0001 C CNN
F 3 "~" H 2650 2100 50  0001 C CNN
	1    2650 2100
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5CAF08E6
P 3100 2100
F 0 "J2" V 3300 2100 50  0000 R CNN
F 1 "IN3" V 3200 2100 50  0000 R CNN
F 2 "KiCadCustomLibs:Conn2pin_2.54mm" H 3100 2100 50  0001 C CNN
F 3 "~" H 3100 2100 50  0001 C CNN
	1    3100 2100
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 5CAF093E
P 3450 2100
F 0 "J3" V 3650 2100 50  0000 R CNN
F 1 "IN2" V 3550 2100 50  0000 R CNN
F 2 "KiCadCustomLibs:Conn2pin_2.54mm" H 3450 2100 50  0001 C CNN
F 3 "~" H 3450 2100 50  0001 C CNN
	1    3450 2100
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5CAF0998
P 3850 2100
F 0 "J4" V 4050 2100 50  0000 R CNN
F 1 "IN1" V 3950 2100 50  0000 R CNN
F 2 "KiCadCustomLibs:Conn2pin_2.54mm" H 3850 2100 50  0001 C CNN
F 3 "~" H 3850 2100 50  0001 C CNN
	1    3850 2100
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDA #PWR0108
U 1 1 5CAF0BD0
P 2750 2300
F 0 "#PWR0108" H 2750 2050 50  0001 C CNN
F 1 "GNDA" H 2755 2127 50  0000 C CNN
F 2 "" H 2750 2300 50  0001 C CNN
F 3 "" H 2750 2300 50  0001 C CNN
	1    2750 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0109
U 1 1 5CAF0D6E
P 3200 2300
F 0 "#PWR0109" H 3200 2050 50  0001 C CNN
F 1 "GNDA" H 3205 2127 50  0000 C CNN
F 2 "" H 3200 2300 50  0001 C CNN
F 3 "" H 3200 2300 50  0001 C CNN
	1    3200 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0110
U 1 1 5CAF0DB7
P 3550 2300
F 0 "#PWR0110" H 3550 2050 50  0001 C CNN
F 1 "GNDA" H 3555 2127 50  0000 C CNN
F 2 "" H 3550 2300 50  0001 C CNN
F 3 "" H 3550 2300 50  0001 C CNN
	1    3550 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0111
U 1 1 5CAF0E00
P 3950 2300
F 0 "#PWR0111" H 3950 2050 50  0001 C CNN
F 1 "GNDA" H 3955 2127 50  0000 C CNN
F 2 "" H 3950 2300 50  0001 C CNN
F 3 "" H 3950 2300 50  0001 C CNN
	1    3950 2300
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J5
U 1 1 5CAF1096
P 4100 3700
F 0 "J5" H 4200 3750 50  0000 L CNN
F 1 "AUX" H 4200 3650 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4100 3700 50  0001 C CNN
F 3 "~" H 4100 3700 50  0001 C CNN
	1    4100 3700
	-1   0    0    1   
$EndComp
$Comp
L power:GNDA #PWR0112
U 1 1 5CAF5D92
P 4350 3850
F 0 "#PWR0112" H 4350 3600 50  0001 C CNN
F 1 "GNDA" H 4355 3677 50  0000 C CNN
F 2 "" H 4350 3850 50  0001 C CNN
F 3 "" H 4350 3850 50  0001 C CNN
	1    4350 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3700 4350 3700
Wire Wire Line
	4350 3700 4350 3850
$Comp
L Connector_Generic:Conn_01x02 J9
U 1 1 5CAF8AB8
P 7200 4250
F 0 "J9" H 7280 4242 50  0000 L CNN
F 1 "POWER" H 7280 4151 50  0000 L CNN
F 2 "KiCadCustomLibs:Conn2pin_2.54mm" H 7200 4250 50  0001 C CNN
F 3 "~" H 7200 4250 50  0001 C CNN
	1    7200 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+9V #PWR0113
U 1 1 5CAF8B9D
P 6900 4150
F 0 "#PWR0113" H 6900 4000 50  0001 C CNN
F 1 "+9V" H 7000 4200 50  0000 C CNN
F 2 "" H 6900 4150 50  0001 C CNN
F 3 "" H 6900 4150 50  0001 C CNN
	1    6900 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0114
U 1 1 5CAF8BEA
P 6900 4400
F 0 "#PWR0114" H 6900 4150 50  0001 C CNN
F 1 "GNDA" H 6905 4227 50  0000 C CNN
F 2 "" H 6900 4400 50  0001 C CNN
F 3 "" H 6900 4400 50  0001 C CNN
	1    6900 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 4150 6900 4250
Wire Wire Line
	6900 4250 7000 4250
Wire Wire Line
	7000 4350 6900 4350
Wire Wire Line
	6900 4350 6900 4400
$EndSCHEMATC
