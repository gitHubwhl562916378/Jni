package com.example.demo.domain;

import java.util.Arrays;

public class Camera
{
    private int id;
    private String name;
    private float[] feature;

    @Override
    public String toString() {
        return "Camera{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", feature=" + Arrays.toString(feature) +
                '}';
    }
}