package com.example.alarmkeyboard;

import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothSocket;

public class BluetoothSettings {

    private static BluetoothSettings instance;
    private BluetoothSocket socket;
    private BluetoothSettings(){

    }

    public static BluetoothSettings getInstance(){
        if(instance == null){
            instance = new BluetoothSettings();
        }
        return instance;
    }

    public void setBluetoothSocket(BluetoothSocket socket){
        this.socket = socket;
    }

    public BluetoothSocket getBluetoothSocket(){
        return socket;
    }

}
