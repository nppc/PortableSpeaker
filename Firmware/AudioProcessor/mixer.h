void controlMixer(void){
  
}


void changeMixerInputs(void){
  curMainScreen = 9;
  curMixInput++;
  if(curMixInput>3){curMixInput=0;}
  
 // showMixerHeader();
  
  if(curMixInput==0){
    showInputHeader();
    showInput(INPUT_MIXER);    
  }else if(curMixInput==1){
    showMixerHeader(1);
    changeGainDisplay(getInputGain(INPUT_MIXER));
  }else if(curMixInput==2){
    showMixerHeader(2);
    changeVolumeDisplay(gainMIXMIC);
  }else if(curMixInput==3){
    showMixerHeader(3);
    changeVolumeDisplay(gainMIXMUSIC);
  }
//  showMixerInput(curMixInput);
  if(curMixInput == 0){encInputChange = 0;}else{encInputChange = 1;} // prepare to adjust volume
 }
