package com.example.demo.better;

import com.example.demo.domain.Camera;

public class Framework {

    static {
        System.load("/home/whl/Documents/java_project/demo/lib/Framework.so");
    }

    public native String whl(String name);

    public native Camera create();

}
