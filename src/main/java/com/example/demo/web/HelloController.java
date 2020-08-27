package com.example.demo.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Map;

@RestController
public class HelloController {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    @RequestMapping("/api/v1/hello")
    public String helllo(){
        return "Hello whk";
    }

    @RequestMapping("/api/v1/jdbc")
    public List<?> jdnc(){
        String sql = "select * from kl_option";
        List<Map<String, Object>> maps = jdbcTemplate.queryForList(sql);

        return maps;
    }


}
