package com.example.alarmkeyboard;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.io.Console;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    private BluetoothAdapter adapter;
    private BluetoothManager manager;
    private BluetoothSocket btSocket;
    private String deviceName, deviceMAC;
    private BluetoothDevice hc05;
    private static final UUID HC05_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");


    @SuppressLint("MissingPermission")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        manager = getSystemService(BluetoothManager.class);
        adapter = manager.getAdapter();


        if(adapter == null){
            Toast.makeText(getApplicationContext(), "NO ADMITE", Toast.LENGTH_LONG).show();
        }

       if(!adapter.isEnabled()){
           Toast.makeText(getApplicationContext(), "You have to enable your mobile bluetooth adapter", Toast.LENGTH_LONG).show();
           finish();
           System.exit(0);
       }else{
           findDevice();
           connectBluetooth();
           Intent startKeyboard = new Intent(this, KeyboardActivity.class);
           startKeyboard.putExtra("bt-socket", btSocket.isConnected());
           startActivity(startKeyboard);
       }

    }

    private void findDevice(){
        if (ActivityCompat.checkSelfPermission(this, android.Manifest.permission.BLUETOOTH_CONNECT) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this,
                    new String[]{android.Manifest.permission.BLUETOOTH_CONNECT}, 1);
            return;
        }
        Set<BluetoothDevice> pairedDevices = adapter.getBondedDevices();
        if(!pairedDevices.isEmpty()){
            for(BluetoothDevice tmp : pairedDevices){
                if(tmp.getName().equals("alarma")){
                    deviceName = tmp.getName();
                    deviceMAC = tmp.getAddress();
                    hc05 = tmp;
                    break;
                }
            }
        }
        if(deviceName == null) {
            Toast.makeText(getApplicationContext(), "PLEASE PAIR YOUR CELLPHONE USING 1234 CODE", Toast.LENGTH_LONG).show();
            finish();
            System.exit(0);
        }
    }

    private void connectBluetooth(){
        if (ActivityCompat.checkSelfPermission(this, android.Manifest.permission.BLUETOOTH_CONNECT) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this,
                    new String[]{android.Manifest.permission.BLUETOOTH_CONNECT}, 1);
            return;
        }
        try {
            btSocket = hc05.createRfcommSocketToServiceRecord(HC05_UUID);
            btSocket.connect();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        try{
            OutputStream msg = btSocket.getOutputStream();
            msg.write("1234".getBytes());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}