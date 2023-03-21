package org.example;

public class Main {
    public static void main(String[] args) {
        KotNorweskiLesny kicia = new KotNorweskiLesny(1,34,"Kicia","Black",true,true);
        Jamnik zbyszek = new Jamnik(3,20,"Zbyszek","Brown",true,"daschund",true);
        Kapibara janusz = new Kapibara(2,40,"Janusz","Dark Brown", true);
        System.out.println("Cat is " +kicia.getAge()+ " years old, has a " + kicia.getFurColor()+ " fur color");
        zbyszek.chaseTail();
        kicia.cleanYourself();
        janusz.swim();
    }
}