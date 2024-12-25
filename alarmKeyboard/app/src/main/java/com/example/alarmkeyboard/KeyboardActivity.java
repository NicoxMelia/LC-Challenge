package com.example.alarmkeyboard;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class KeyboardActivity extends AppCompatActivity {

    private String key = "";
    private TextView txtKey;
    private int[] keyboard;
    private Button btnClear, btnOk;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_keyboard);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        txtKey = findViewById(R.id.txtKey);
        btnOk = findViewById(R.id.btn_submit);
        keyboard = new int[]{
                R.id.btn_0, R.id.btn_1, R.id.btn_2,
                R.id.btn_3, R.id.btn_4, R.id.btn_5,
                R.id.btn_6, R.id.btn_7, R.id.btn_8,
                R.id.btn_9
        };

        for(int btn : keyboard){
            Button aux = findViewById(btn);
            aux.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    key += ((Button) v).getText().toString();
                    txtKey.setText("Key: " + key);
                }
            });
        }

        btnClear = findViewById(R.id.btn_clear);
        btnClear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                key = "";
                txtKey.setText("Key: " + key);
            }
        });

        btnOk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //send Key to arduino
            }
        });

    }
}