//
//
//  Generated by StarUML(tm) Java Add-In
//
//  @ Project : Untitled
//  @ File Name : Kapibara.java
//  @ Date : 15.03.2023
//  @ Author : 
//
//
package org.example;



public class Kapibara extends Ssak {
	private boolean hasWeb;
	public void swim() {
		System.out.println("The capybara is swimming!");
	}


	public Kapibara(int age, int height, String name, String furColor, boolean hasWeb) {
		super(age, height, name, furColor);
		this.hasWeb = hasWeb;
	}
}
