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
L IC_Generic:IC10 U?
U 1 1 5CB1C9D8
P 5400 3400
F 0 "U?" H 5400 3550 50  0000 C CNN
F 1 "MAX4062" H 5400 3400 50  0000 C CNN
F 2 "" H 5400 3400 50  0001 C CNN
F 3 "" H 5400 3400 50  0001 C CNN
	1    5400 3400
	1    0    0    -1  
$EndComp
Text Label 5050 3300 2    50   ~ 0
INT
Text Label 5050 3400 2    50   ~ 0
OUT
Text Label 5050 3200 2    50   ~ 0
G2
Text Label 5050 3500 2    50   ~ 0
BIAS
Text Label 5050 3600 2    50   ~ 0
VCC
Text Label 5750 3600 0    50   ~ 0
IN+
Text Label 5750 3500 0    50   ~ 0
IN-
Text Label 5750 3400 0    50   ~ 0
GND
Text Label 5750 3300 0    50   ~ 0
AUX_IN
Text Label 5750 3200 0    50   ~ 0
G1
$Comp
L Device:R R?
U 1 1 5CB1CAC6
P 5400 3000
F 0 "R?" V 5193 3000 50  0000 C CNN
F 1 "11K" V 5284 3000 50  0000 C CNN
F 2 "" V 5330 3000 50  0001 C CNN
F 3 "~" H 5400 3000 50  0001 C CNN
	1    5400 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 3200 4900 3200
Wire Wire Line
	4900 3200 4900 3000
Wire Wire Line
	4900 3000 5250 3000
Wire Wire Line
	5750 3200 5900 3200
Wire Wire Line
	5900 3200 5900 3000
Wire Wire Line
	5900 3000 5550 3000
$Comp
L Device:C C?
U 1 1 5CB1CB6F
P 6250 3800
F 0 "C?" V 6300 3900 50  0000 C CNN
F 1 "100n" V 6200 3950 50  0000 C CNN
F 2 "" H 6288 3650 50  0001 C CNN
F 3 "~" H 6250 3800 50  0001 C CNN
	1    6250 3800
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5CB1CC59
P 6250 3550
F 0 "C?" V 6300 3650 50  0000 C CNN
F 1 "100n" V 6200 3700 50  0000 C CNN
F 2 "" H 6288 3400 50  0001 C CNN
F 3 "~" H 6250 3550 50  0001 C CNN
	1    6250 3550
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5CB1CC7B
P 6250 3300
F 0 "C?" V 6300 3400 50  0000 C CNN
F 1 "100n" V 6200 3450 50  0000 C CNN
F 2 "" H 6288 3150 50  0001 C CNN
F 3 "~" H 6250 3300 50  0001 C CNN
	1    6250 3300
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5CB1CC9D
P 6300 2650
F 0 "C?" H 6400 2750 50  0000 C CNN
F 1 "100n" H 6100 2650 50  0000 C CNN
F 2 "" H 6338 2500 50  0001 C CNN
F 3 "~" H 6300 2650 50  0001 C CNN
	1    6300 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3600 5950 3600
Wire Wire Line
	5950 3600 5950 3800
Wire Wire Line
	5950 3800 6100 3800
Wire Wire Line
	5750 3500 6000 3500
Wire Wire Line
	6000 3500 6000 3550
Wire Wire Line
	6000 3550 6100 3550
Wire Wire Line
	5750 3300 6100 3300
$Comp
L power:GND #PWR?
U 1 1 5CB1CFF7
P 6050 3400
F 0 "#PWR?" H 6050 3150 50  0001 C CNN
F 1 "GND" H 6050 3450 50  0000 C CNN
F 2 "" H 6050 3400 50  0001 C CNN
F 3 "" H 6050 3400 50  0001 C CNN
	1    6050 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3400 6050 3400
$Comp
L Device:C C?
U 1 1 5CB1D13D
P 4600 3500
F 0 "C?" V 4650 3600 50  0000 C CNN
F 1 "100n" V 4550 3650 50  0000 C CNN
F 2 "" H 4638 3350 50  0001 C CNN
F 3 "~" H 4600 3500 50  0001 C CNN
	1    4600 3500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5050 3500 4750 3500
$Comp
L power:VCC #PWR?
U 1 1 5CB1D2BF
P 4850 3600
F 0 "#PWR?" H 4850 3450 50  0001 C CNN
F 1 "VCC" H 4868 3773 50  0000 C CNN
F 2 "" H 4850 3600 50  0001 C CNN
F 3 "" H 4850 3600 50  0001 C CNN
	1    4850 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4850 3600 5050 3600
$Comp
L Device:R R?
U 1 1 5CB1D67D
P 4600 3150
F 0 "R?" H 4530 3104 50  0000 R CNN
F 1 "100K" H 4530 3195 50  0000 R CNN
F 2 "" V 4530 3150 50  0001 C CNN
F 3 "~" H 4600 3150 50  0001 C CNN
	1    4600 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	5050 3300 4600 3300
$Comp
L power:VCC #PWR?
U 1 1 5CB1D8C5
P 4600 3000
F 0 "#PWR?" H 4600 2850 50  0001 C CNN
F 1 "VCC" H 4617 3173 50  0000 C CNN
F 2 "" H 4600 3000 50  0001 C CNN
F 3 "" H 4600 3000 50  0001 C CNN
	1    4600 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CB1D908
P 4250 3650
F 0 "#PWR?" H 4250 3400 50  0001 C CNN
F 1 "GND" H 4250 3500 50  0000 C CNN
F 2 "" H 4250 3650 50  0001 C CNN
F 3 "" H 4250 3650 50  0001 C CNN
	1    4250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3650 4250 3500
Wire Wire Line
	4250 3500 4450 3500
Wire Wire Line
	5050 3400 4800 3400
Wire Wire Line
	4800 3400 4800 3350
Wire Wire Line
	4800 3350 4250 3350
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5CB1DE7E
P 4050 3450
F 0 "J?" H 4050 3250 50  0000 C CNN
F 1 "OUT" H 4200 3400 50  0000 C CNN
F 2 "" H 4050 3450 50  0001 C CNN
F 3 "~" H 4050 3450 50  0001 C CNN
	1    4050 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 3450 4250 3500
Connection ~ 4250 3500
$Comp
L power:GND #PWR?
U 1 1 5CB1E436
P 6300 2800
F 0 "#PWR?" H 6300 2550 50  0001 C CNN
F 1 "GND" H 6300 2650 50  0000 C CNN
F 2 "" H 6300 2800 50  0001 C CNN
F 3 "" H 6300 2800 50  0001 C CNN
	1    6300 2800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5CB1E4AD
P 6300 2500
F 0 "#PWR?" H 6300 2350 50  0001 C CNN
F 1 "VCC" H 6317 2673 50  0000 C CNN
F 2 "" H 6300 2500 50  0001 C CNN
F 3 "" H 6300 2500 50  0001 C CNN
	1    6300 2500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5CB1E5BE
P 7000 3200
F 0 "J?" H 7000 3300 50  0000 C CNN
F 1 "AUX" H 7150 3150 50  0000 C CNN
F 2 "" H 7000 3200 50  0001 C CNN
F 3 "~" H 7000 3200 50  0001 C CNN
	1    7000 3200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5CB1E65A
P 7000 3550
F 0 "J?" H 7000 3650 50  0000 C CNN
F 1 "MIC" H 7150 3500 50  0000 C CNN
F 2 "" H 7000 3550 50  0001 C CNN
F 3 "~" H 7000 3550 50  0001 C CNN
	1    7000 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3550 6600 3550
Wire Wire Line
	6400 3300 6550 3300
Wire Wire Line
	6550 3300 6550 3200
Wire Wire Line
	6550 3200 6800 3200
$Comp
L power:GND #PWR?
U 1 1 5CB1F18D
P 6800 3300
F 0 "#PWR?" H 6800 3050 50  0001 C CNN
F 1 "GND" H 6800 3150 50  0000 C CNN
F 2 "" H 6800 3300 50  0001 C CNN
F 3 "" H 6800 3300 50  0001 C CNN
	1    6800 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CB1F1B0
P 6600 3550
F 0 "#PWR?" H 6600 3300 50  0001 C CNN
F 1 "GND" H 6600 3400 50  0000 C CNN
F 2 "" H 6600 3550 50  0001 C CNN
F 3 "" H 6600 3550 50  0001 C CNN
	1    6600 3550
	1    0    0    -1  
$EndComp
Connection ~ 6600 3550
Wire Wire Line
	6600 3550 6800 3550
Wire Wire Line
	6400 3800 6750 3800
Wire Wire Line
	6750 3800 6750 3650
Wire Wire Line
	6750 3650 6800 3650
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5CB1F7EC
P 4050 2600
F 0 "J?" H 4050 2400 50  0000 C CNN
F 1 "PWR" H 4200 2550 50  0000 C CNN
F 2 "" H 4050 2600 50  0001 C CNN
F 3 "~" H 4050 2600 50  0001 C CNN
	1    4050 2600
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5CB1F82C
P 4250 2500
F 0 "#PWR?" H 4250 2350 50  0001 C CNN
F 1 "VCC" H 4267 2673 50  0000 C CNN
F 2 "" H 4250 2500 50  0001 C CNN
F 3 "" H 4250 2500 50  0001 C CNN
	1    4250 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5CB1F84F
P 4250 2600
F 0 "#PWR?" H 4250 2350 50  0001 C CNN
F 1 "GND" H 4250 2450 50  0000 C CNN
F 2 "" H 4250 2600 50  0001 C CNN
F 3 "" H 4250 2600 50  0001 C CNN
	1    4250 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J?
U 1 1 5CB2036E
P 4050 3050
F 0 "J?" H 4050 2950 50  0000 C CNN
F 1 "INT" H 4200 3050 50  0000 C CNN
F 2 "" H 4050 3050 50  0001 C CNN
F 3 "~" H 4050 3050 50  0001 C CNN
	1    4050 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 3050 4400 3050
Wire Wire Line
	4400 3050 4400 3300
Wire Wire Line
	4400 3300 4600 3300
Connection ~ 4600 3300
$EndSCHEMATC
