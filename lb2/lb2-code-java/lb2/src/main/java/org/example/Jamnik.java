//
//
//  Generated by StarUML(tm) Java Add-In
//
//  @ Project : Untitled
//  @ File Name : Jamnik.java
//  @ Date : 15.03.2023
//  @ Author : 
//
//
package org.example;



public class Jamnik extends Pies {
	public boolean floppyEars;
	public void catchABall() {
		System.out.println("Catched a ball!");
	}

	public Jamnik(int age, int height, String name, String furColor, boolean isMixed, String race, boolean floppyEars) {
		super(age, height, name, furColor, isMixed, race);
		this.floppyEars = floppyEars;
	}
}