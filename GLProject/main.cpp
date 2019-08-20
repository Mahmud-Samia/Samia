#include<windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include<iostream>
#define PI 3.1416

using namespace std;
void introscreen();

static float	tx= 0.0, cloudleftx=0,cloudmiddlex=0,cloudrightx=0,cloudrightupx=0;
static float    ty=0.0;

static float txB=0.0;
static float tyB=0.0;

static float txR=0.0;
static float tyR=0.0;


void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle1 = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle1 = 2 * PI * i / 100;
			glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
		}

	glEnd();
}

void HalfCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle1 = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i <50; i++)
		{
			angle1 = 2 * PI * i / 150;
			glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
		}

	glEnd();
}

void renderbitmap(float x, float y, void *font, char *string){
    char *c;
    glRasterPos2f(x,y);
    for(c=string; *c!= '\0'; c++){

        glutBitmapCharacter(font, *c);
    }

}
void introscreen(){
glColor3ub(255,255,255);
char buf[100]={0};
sprintf(buf, "Beauty   Of   Nature");
renderbitmap(-10,40, GLUT_BITMAP_TIMES_ROMAN_24,buf);

sprintf(buf, "Beautiful   Village   Scenario");
renderbitmap(-12,20, GLUT_BITMAP_TIMES_ROMAN_24,buf);


sprintf(buf, "Press  'd'  'r'  'n'  to  see  the  view  of  the  nature");
renderbitmap(-19,0, GLUT_BITMAP_TIMES_ROMAN_24,buf);


}

void screen(){

     glBegin(GL_QUADS);

       glColor3ub(234, 243, 245);

	glVertex2f(-50.0f, 110.0f);
	glColor3ub(93, 78, 105);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(108, 88, 124);
	glVertex2f(50.0f, -90.0f);
	glColor3ub(78, 30, 115);
    glVertex2f(-50.0f, -90.0f);

            glEnd();


}

void sun(){
    glPushMatrix();
        glTranslated(-10,98,0);
        glScaled(0.5,1.5,0);
        glColor3f(1,0.843,0);
        circle(4,4);
    glPopMatrix();
}
void moon(){
    glPushMatrix();
        glTranslated(-30,98,0);
        glScaled(0.5,1.5,0);
        glColor3ub(255,255,51);
        HalfCircle(4,4);
    glPopMatrix();
}






void Hill(){
    glBegin(GL_TRIANGLES);

       glColor3ub(102 ,102, 0);

	glVertex2f(-38.0f, 20.0f);
	glColor3ub(76 ,53, 0);
    glVertex2f(-34.0f, 35.0f);
    glColor3ub(76 ,53, 0);
    glVertex2f(-26.0f, 20.0f);


    glColor3ub(102 ,102, 0);
    glVertex2f(-26.0f, 20.0f);
    glColor3ub(76 ,53, 0);
    glVertex2f(-23.0f, 40.0f);
    glColor3ub(76 ,53, 0);
    glVertex2f(-19.0f, 20.0f);

    glColor3ub(76 ,53, 0);
    glVertex2f(-35.0f, 20.0f);
    glVertex2f(-28.0f, 45.0f);
    glVertex2f(-22.0f, 20.0f);

    glColor3ub(102 ,102, 0);
    glVertex2f(-22.0f, 20.0f);
    glColor3ub(128 ,255, 0);
    glVertex2f(-19.0f, 55.0f);
    glColor3ub(76 ,53, 0);
    glVertex2f(-15.0f, 20.0f);


    glColor3ub(76 ,53, 0);
    glVertex2f(-22.0f, 20.0f);
    glColor3ub(255 ,255, 0);
    glVertex2f(-10.0f, 66.0f);
    glColor3ub(128 ,255, 0);
    glVertex2f(-1.0f, 20.0f);

    glColor3ub(76 ,53, 0);
    glVertex2f(-15.0f, 20.0f);
    glVertex2f(-10.0f, 45.0f);
    glVertex2f(-3.0f, 20.0f);


            glEnd();
}

void Ground(){
    glBegin(GL_POLYGON);

       glColor3ub(153, 255, 51);

	glVertex2f(-50.0f, 20.0f);
	glVertex2f(0.0f,20.0f);
	//glColor3ub(210, 233, 238);
	glVertex2f(8.0f, 5.0f);
	//glColor3ub(151, 191, 208);
	//glVertex2f(5.0f, -5.0f);





	glColor3ub(102, 204, 0);
    glVertex2f(5.0f, -7.0f);
    glVertex2f(-2.0f, -15.0f);
    glVertex2f(10.0f, -25.0f);
    glVertex2f(0.0f, -30.0f);




    glColor3ub(0, 153, 76);
    glVertex2f(12.0f, -35.0f);
    glVertex2f(-3.0f, -50.0f);
    glVertex2f(11.0f, -90.0f);
    glVertex2f(-50.0f, -90.0f);


glEnd();
}

void Grass(){
    glBegin(GL_POLYGON);

       glColor3ub(255, 255, 0);
      glVertex2f(-10.0f, -10.0f);
    glVertex2f(-10.0f, -2.0f);
    glVertex2f(-8.0f, 7.0f);
    glVertex2f(-5.0f, -2.0f);
    glVertex2f(-5.0f, -10.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(102, 51, 0);
      glVertex2f(-8.0f, 7.0f);
      glVertex2f(-8.0f, 12.0f);
      glVertex2f(-8.2f, 12.0f);
      glVertex2f(-8.2f, 7.0f);






glEnd();
}



void Tree()
{

    glBegin(GL_POLYGON);

       glColor3ub(153, 76, 0);

	glVertex2f(-44.0f, -10.0f);
	glVertex2f(-42.0f,-10.0f);
	glVertex2f(-42.0f, -60.0f);
	glVertex2f(-44.0f, -60.0f);

	glEnd();

	 glBegin(GL_POLYGON);

       glColor3ub(153, 76, 0);
    glVertex2f(-42.0f, -60.0f);
	glVertex2f(-38.0f, -62.0f);
	glVertex2f(-44.0f, -61.0f);
	glVertex2f(-42.0f, -67.0f);
	glVertex2f(-44.0f, -61.0f);
	glVertex2f(-47.0f, -64.0f);
	glVertex2f(-44.0f, -60.0f);


glEnd();
glPushMatrix();
        glTranslated(-41,30,0);
        glScaled(0.5,1.5,0);
        glColor3ub(128,255,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-45,22,0);
        glScaled(0.5,1.5,0);
        glColor3ub(51,102,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-38,20,0);
        glScaled(0.5,1.5,0);
        glColor3ub(51,102,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-39,18,0);
        glScaled(0.5,1.5,0);
        glColor3ub(51,102,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-44,18,0);
        glScaled(0.5,1.5,0);
        glColor3ub(51,102,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-41,18,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(8,8);
       glPopMatrix();
glPushMatrix();
        glTranslated(-40,12,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,204,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-37,14,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,204,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-40,12,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,204,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-46,9,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,204,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-38,2,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,204,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-40,-1,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-44,-5,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,204,0);
        circle(6,6);
       glPopMatrix();
glPushMatrix();
        glTranslated(-47,-6,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(6,6);
       glPopMatrix();
   glPushMatrix();
        glTranslated(-44,-8,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(6,6);
       glPopMatrix();
    glPushMatrix();
        glTranslated(-39,-8,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(6,6);
       glPopMatrix();
    glPushMatrix();
        glTranslated(-40,-8,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(4,4);
       glPopMatrix();
    glPushMatrix();
        glTranslated(-41,-10,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(4,4);
       glPopMatrix();
    glPushMatrix();
        glTranslated(-44,-10,0);
        glScaled(0.5,1.5,0);
        glColor3ub(0,102,0);
        circle(4,4);
    glPopMatrix();


}
void River(){


    glBegin(GL_POLYGON);

       glColor3ub(0, 0, 255);

	glVertex2f(50.0f, 20.0f);
	glVertex2f(0.0f,20.0f);
	glColor3ub(0, 128, 255);
	glVertex2f(8.0f, 5.0f);

     glColor3ub(51, 153, 255);

    glVertex2f(5.0f, -7.0f);
    glVertex2f(-2.0f, -15.0f);
    glColor3ub(102, 178, 255);
    glVertex2f(10.0f, -25.0f);
    glVertex2f(0.0f, -30.0f);




   // glColor3ub(102, 255, 255);
    glVertex2f(12.0f, -35.0f);
    glVertex2f(-3.0f, -50.0f);
    glVertex2f(11.0f, -90.0f);
    glVertex2f(50.0f, -90.0f);


glEnd();




}

void RiverR(){


    glBegin(GL_POLYGON);

         glColor3ub(109, 120,124);

	glVertex2f(50.0f, 20.0f);
	glVertex2f(0.0f,20.0f);
	glColor3ub(87, 119, 131);
	glVertex2f(8.0f, 5.0f);

      glColor3ub(60, 83, 91);

    glVertex2f(5.0f, -7.0f);
    glVertex2f(-2.0f, -15.0f);
    glColor3ub(139, 168, 178);
    glVertex2f(10.0f, -25.0f);
    glVertex2f(0.0f, -30.0f);




   // glColor3ub(102, 255, 255);
    glVertex2f(12.0f, -35.0f);
    glVertex2f(-3.0f, -50.0f);
    glVertex2f(11.0f, -90.0f);
    glVertex2f(50.0f, -90.0f);


glEnd();
}

void House1()
{

    glBegin(GL_QUADS);

       glColor3ub(153, 0, 0);

	glVertex2f(-30.0f, 5.0f);
	glVertex2f(-25.0f,13.0f);
	//glColor3ub(210, 233, 238);  //top
	glVertex2f(-15.0f, 13.0f);
	//glColor3ub(151, 191, 208);
	glVertex2f(-10.0f, 5.0f);

	glColor3ub(153, 76, 0);
	glVertex2f(-28.0f, 5.0f);
	glVertex2f(-28.0f, -10.0f); //body
	glVertex2f(-12.0f, -10.0f);
	glVertex2f(-12.0f, 5.0f);

	glColor3ub(64, 64, 64);
	glVertex2f(-22.0f, 1.0f);
	glVertex2f(-22.0f, -10.0f); //dor
	glVertex2f(-19.0f, -10.0f);
	glVertex2f(-19.0f, 1.0f);

	glColor3ub(64, 64, 64);
	glVertex2f(-17.0f, 3.0f);
	glVertex2f(-17.0f, -3.0f); //window
	glVertex2f(-15.0f, -3.0f);
	glVertex2f(-15.0f, 3.0f);

    glEnd();
}




void House2()
{

    glBegin(GL_POLYGON);

       glColor3ub(96, 96, 96);

	glVertex2f(-40.0f, 3.0f);
	glVertex2f(-20.0f,3.0f);
	glVertex2f(-30.0f,15.0f);  //top
	glVertex2f(-40.0f,3.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3ub(255,255,0);
	glVertex2f(-37.0f, 3.0f);
	glVertex2f(-37.0f,-15.0f);  //body
	glVertex2f(-23.0f,-15.0f);
	glVertex2f(-23.0f,3.0f);

	glEnd();

	glBegin(GL_QUADS);

	  glColor3ub(153, 76, 0);

	glVertex2f(-31.0f, -15.0f);
	glVertex2f(-29.0f,-15.0f);  //door
	glVertex2f(-29.0f,-6.0f);
	glVertex2f(-31.0f,-6.0f);

	 glColor3ub(153, 76, 0);

	glVertex2f(-35.0f, -1.0f);
	glVertex2f(-35.0f,-10.0f);
	glVertex2f(-33.0f,-10.0f);  //leftwindow
	glVertex2f(-33.0f,-1.0f);


	 glColor3ub(153, 76, 0);

	glVertex2f(-27.0f, -1.0f);
	glVertex2f(-27.0f,-10.0f);  //rightwindow
	glVertex2f(-25.0f,-10.0f);
	glVertex2f(-25.0f,-1.0f);







glEnd();
}

void Path(){


    glBegin(GL_POLYGON);

       glColor3ub(153, 153, 0);

	glVertex2f(-22.0f, -10.0f);
    glVertex2f(4.0f,-90.0f);
	glVertex2f(8.0f, -90.0f);
	glVertex2f(-19.0f, -10.0f);

glEnd();

 glBegin(GL_POLYGON);

       glColor3ub(153, 153, 0);

	glVertex2f(-31.0f, -15.0f);
    glVertex2f(-45.0f,-90.0f);
	glVertex2f(-41.0f, -90.0f);
	glVertex2f(-29.0f, -15.0f);

glEnd();

}

void Rain(){

     tyR=tyR-11;
         if(tyR<-190){
            tyR=100;
         }

    glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, 110.0f);
	glVertex2f(-48.8f,110.0f);
	glVertex2f(-48.8f,100.0f);
	glVertex2f(-49.0f, 100.0f);
        glEnd();

        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, 70.0f);
	glVertex2f(-48.8f,70.0f);
	glVertex2f(-48.8f, 60.0f);
	glVertex2f(-49.0f, 60.0f);
        glEnd();

        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, 30.0f);
	glVertex2f(-48.8f, 30.0f);
	glVertex2f(-48.8f, 20.0f);
	glVertex2f(-49.0f, 20.0f);
        glEnd();

        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, -10.0f);
	glVertex2f(-48.8f, -10.0f);
	glVertex2f(-48.8f, -20.0f);
	glVertex2f(-49.0f, -20.0f);
        glEnd();

        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, -50.0f);
	glVertex2f(-48.8f, -50.0f);
	glVertex2f(-48.8f, -60.0f);
	glVertex2f(-49.0f, -60.0f);
        glEnd();

      glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-45.0f, 110.0f);
	glVertex2f(-44.8f, 110.0f);
	glVertex2f(-44.8f, 100.0f);
	glVertex2f(-45.0f, 100.0f);
        glEnd();

         glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-45.0f, 70.0f);
	glVertex2f(-44.8f, 70.0f);
	glVertex2f(-44.8f, 60.0f);
	glVertex2f(-45.0f, 60.0f);
        glEnd();
        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-45.0f, 30.0f);
	glVertex2f(-44.8f, 30.0f);
	glVertex2f(-44.8f, 20.0f);
	glVertex2f(-45.0f, 20.0f);
        glEnd();

        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-45.0f, -10.0f);
	glVertex2f(-44.8f, -10.0f);
	glVertex2f(-44.8f, -20.0f);
	glVertex2f(-45.0f, -20.0f);
        glEnd();



        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-41.0f, 110.0f);
	glVertex2f(-40.8f, 110.0f);
	glVertex2f(-40.8f, 100.0f);
	glVertex2f(-41.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-41.0f, 70.0f);
	glVertex2f(-40.8f, 70.0f);
	glVertex2f(-40.8f, 60.0f);
	glVertex2f(-41.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-41.0f, 30.0f);
	glVertex2f(-40.8f, 30.0f);
	glVertex2f(-40.8f, 20.0f);
	glVertex2f(-41.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-41.0f, -10.0f);
	glVertex2f(-40.8f, -10.0f);
	glVertex2f(-40.8f, -20.0f);
	glVertex2f(-41.0f, -20.0f);
           glEnd();



            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-37.0f, 110.0f);
	glVertex2f(-36.8f, 110.0f);
	glVertex2f(-36.8f, 100.0f);
	glVertex2f(-37.0f, 100.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-37.0f, 70.0f);
	glVertex2f(-36.8f, 70.0f);
	glVertex2f(-36.8f, 60.0f);
	glVertex2f(-37.0f, 60.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-37.0f, 30.0f);
	glVertex2f(-36.8f, 30.0f);
	glVertex2f(-36.8f, 20.0f);
	glVertex2f(-37.0f, 20.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-37.0f, -10.0f);
	glVertex2f(-36.8f, -10.0f);
	glVertex2f(-36.8f, -20.0f);
	glVertex2f(-37.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-33.0f, 110.0f);
	glVertex2f(-32.8f, 110.0f);
	glVertex2f(-32.8f, 100.0f);
	glVertex2f(-33.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-33.0f, 70.0f);
	glVertex2f(-32.8f, 70.0f);
	glVertex2f(-32.8f, 60.0f);
	glVertex2f(-33.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-33.0f, 30.0f);
	glVertex2f(-32.8f, 30.0f);
	glVertex2f(-32.8f, 20.0f);
	glVertex2f(-33.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-33.0f, -10.0f);
	glVertex2f(-32.8f, -10.0f);
	glVertex2f(-32.8f, -20.0f);
	glVertex2f(-33.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-29.0f, 110.0f);
	glVertex2f(-28.8f, 110.0f);
	glVertex2f(-28.8f, 100.0f);
	glVertex2f(-29.0f, 100.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-29.0f, 70.0f);
	glVertex2f(-28.8f, 70.0f);
	glVertex2f(-28.8f, 60.0f);
	glVertex2f(-29.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-29.0f, 30.0f);
	glVertex2f(-28.8f, 30.0f);
	glVertex2f(-28.8f, 20.0f);
	glVertex2f(-29.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-29.0f, -10.0f);
	glVertex2f(-28.8f, -10.0f);
	glVertex2f(-28.8f, -20.0f);
	glVertex2f(-29.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-25.0f, 110.0f);
	glVertex2f(-24.8f, 110.0f);
	glVertex2f(-24.8f, 100.0f);
	glVertex2f(-25.0f, 100.0f);
           glEnd();
            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-25.0f, 70.0f);
	glVertex2f(-24.8f, 70.0f);
	glVertex2f(-24.8f, 60.0f);
	glVertex2f(-25.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-25.0f, 30.0f);
	glVertex2f(-24.8f, 30.0f);
	glVertex2f(-24.8f, 20.0f);
	glVertex2f(-25.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-25.0f, -10.0f);
	glVertex2f(-24.8f, -10.0f);
	glVertex2f(-24.8f, -20.0f);
	glVertex2f(-25.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-21.0f, 110.0f);
	glVertex2f(-20.8f, 110.0f);
	glVertex2f(-20.8f, 100.0f);
	glVertex2f(-21.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-21.0f, 70.0f);
	glVertex2f(-20.8f, 70.0f);
	glVertex2f(-20.8f, 60.0f);
	glVertex2f(-21.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-21.0f, 30.0f);
	glVertex2f(-20.8f, 30.0f);
	glVertex2f(-20.8f, 20.0f);
	glVertex2f(-21.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-21.0f, -10.0f);
	glVertex2f(-20.8f, -10.0f);
	glVertex2f(-20.8f, -20.0f);
	glVertex2f(-21.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-17.0f, 110.0f);
	glVertex2f(-16.8f, 110.0f);
	glVertex2f(-16.8f, 100.0f);
	glVertex2f(-17.0f, 100.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-17.0f, 70.0f);
	glVertex2f(-16.8f, 70.0f);
	glVertex2f(-16.8f, 60.0f);
	glVertex2f(-17.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-17.0f, 30.0f);
	glVertex2f(-16.8f, 30.0f);
	glVertex2f(-16.8f, 20.0f);
	glVertex2f(-17.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-17.0f, -10.0f);
	glVertex2f(-16.8f, -10.0f);
	glVertex2f(-16.8f, -20.0f);
	glVertex2f(-17.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-13.0f, 110.0f);
	glVertex2f(-12.8f, 110.0f);
	glVertex2f(-12.8f, 100.0f);
	glVertex2f(-13.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-13.0f, 70.0f);
	glVertex2f(-12.8f, 70.0f);
	glVertex2f(-12.8f, 60.0f);
	glVertex2f(-13.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-13.0f, 30.0f);
	glVertex2f(-12.8f, 30.0f);
	glVertex2f(-12.8f, 20.0f);
	glVertex2f(-13.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-13.0f, -10.0f);
	glVertex2f(-12.8f, -10.0f);
	glVertex2f(-12.8f, -20.0f);
	glVertex2f(-13.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-9.0f, 110.0f);
	glVertex2f(-8.8f, 110.0f);
	glVertex2f(-8.8f, 100.0f);
	glVertex2f(-9.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-9.0f, 70.0f);
	glVertex2f(-8.8f, 70.0f);
	glVertex2f(-8.8f, 60.0f);
	glVertex2f(-9.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-9.0f, 30.0f);
	glVertex2f(-8.8f, 30.0f);
	glVertex2f(-8.8f, 20.0f);
	glVertex2f(-9.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-9.0f, -10.0f);
	glVertex2f(-8.8f, -10.0f);
	glVertex2f(-8.8f, -20.0f);
	glVertex2f(-9.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-5.0f, 110.0f);
	glVertex2f(-4.8f, 110.0f);
	glVertex2f(-4.8f, 100.0f);
	glVertex2f(-5.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-5.0f, 70.0f);
	glVertex2f(-4.8f, 70.0f);
	glVertex2f(-4.8f, 60.0f);
	glVertex2f(-5.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-5.0f, 30.0f);
	glVertex2f(-4.8f, 30.0f);
	glVertex2f(-4.8f, 20.0f);
	glVertex2f(-5.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-5.0f, -10.0f);
	glVertex2f(-4.8f, -10.0f);
	glVertex2f(-4.8f, -20.0f);
	glVertex2f(-5.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-1.0f, 110.0f);
	glVertex2f(-0.8f, 110.0f);
	glVertex2f(-0.8f, 100.0f);
	glVertex2f(-1.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-1.0f, 70.0f);
	glVertex2f(-0.8f, 70.0f);
	glVertex2f(-0.8f, 60.0f);
	glVertex2f(-1.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-1.0f, 30.0f);
	glVertex2f(-0.8f, 30.0f);
	glVertex2f(-0.8f, 20.0f);
	glVertex2f(-1.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-1.0f, -10.0f);
	glVertex2f(-0.8f, -10.0f);
	glVertex2f(-0.8f, -20.0f);
	glVertex2f(-1.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(3.0f, 110.0f);
	glVertex2f(2.8f, 110.0f);
	glVertex2f(2.8f, 100.0f);
	glVertex2f(3.0f, 100.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(3.0f, 70.0f);
	glVertex2f(2.8f, 70.0f);
	glVertex2f(2.8f, 60.0f);
	glVertex2f(3.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(3.0f, 30.0f);
	glVertex2f(2.8f, 30.0f);
	glVertex2f(2.8f, 20.0f);
	glVertex2f(3.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(3.0f, -10.0f);
	glVertex2f(2.8f, -10.0f);
	glVertex2f(2.8f, -20.0f);
	glVertex2f(3.0f, -20.0f);
           glEnd();

          glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(7.0f, 110.0f);
	glVertex2f(6.8f, 110.0f);
	glVertex2f(6.8f, 100.0f);
	glVertex2f(7.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(7.0f, 70.0f);
	glVertex2f(6.8f, 70.0f);
	glVertex2f(6.8f, 60.0f);
	glVertex2f(7.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(7.0f, 30.0f);
	glVertex2f(6.8f, 30.0f);
	glVertex2f(6.8f, 20.0f);
	glVertex2f(7.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(7.0f, -10.0f);
	glVertex2f(6.8f, -10.0f);
	glVertex2f(6.8f, -20.0f);
	glVertex2f(7.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(11.0f, 110.0f);
	glVertex2f(10.8f, 110.0f);
	glVertex2f(10.8f, 100.0f);
	glVertex2f(11.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(11.0f, 70.0f);
	glVertex2f(10.8f, 70.0f);
	glVertex2f(10.8f, 60.0f);
	glVertex2f(11.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(11.0f, 30.0f);
	glVertex2f(10.8f, 30.0f);
	glVertex2f(10.8f, 20.0f);
	glVertex2f(11.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(11.0f, -10.0f);
	glVertex2f(10.8f, -10.0f);
	glVertex2f(10.8f, -20.0f);
	glVertex2f(11.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(15.0f, 110.0f);
	glVertex2f(14.8f, 110.0f);
	glVertex2f(14.8f, 100.0f);
	glVertex2f(15.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(15.0f, 70.0f);
	glVertex2f(14.8f, 70.0f);
	glVertex2f(14.8f, 60.0f);
	glVertex2f(15.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(15.0f, 30.0f);
	glVertex2f(14.8f, 30.0f);
	glVertex2f(14.8f, 20.0f);
	glVertex2f(15.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(15.0f, -10.0f);
	glVertex2f(14.8f, -10.0f);
	glVertex2f(14.8f, -20.0f);
	glVertex2f(15.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(19.0f, 110.0f);
	glVertex2f(18.5f, 110.0f);
	glVertex2f(18.5f, 100.0f);
	glVertex2f(19.0f, 110.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(19.0f, 70.0f);
	glVertex2f(18.8f, 70.0f);
	glVertex2f(18.8f, 60.0f);
	glVertex2f(19.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(19.0f, 30.0f);
	glVertex2f(18.8f, 30.0f);
	glVertex2f(18.8f, 20.0f);
	glVertex2f(19.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(19.0f, -10.0f);
	glVertex2f(18.8f, -10.0f);
	glVertex2f(18.8f, -20.0f);
	glVertex2f(19.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(23.0f, 110.0f);
	glVertex2f(22.8f, 110.0f);
	glVertex2f(22.8f, 100.0f);
	glVertex2f(23.0f, 100.0f);
           glEnd();
            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(23.0f, 70.0f);
	glVertex2f(22.8f, 70.0f);
	glVertex2f(22.8f, 60.0f);
	glVertex2f(23.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(23.0f, 30.0f);
	glVertex2f(22.8f, 30.0f);
	glVertex2f(22.8f, 20.0f);
	glVertex2f(23.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(23.0f, -10.0f);
	glVertex2f(22.8f, -10.0f);
	glVertex2f(22.8f, -20.0f);
	glVertex2f(23.0f, -20.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(27.0f, 110.0f);
	glVertex2f(26.8f, 110.0f);
	glVertex2f(26.8f, 100.0f);
	glVertex2f(27.0f, 100.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(27.0f, 70.0f);
	glVertex2f(26.8f, 70.0f);
	glVertex2f(26.8f, 60.0f);
	glVertex2f(27.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(27.0f, 30.0f);
	glVertex2f(26.8f, 30.0f);
	glVertex2f(26.8f, 20.0f);
	glVertex2f(27.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(27.0f, -10.0f);
	glVertex2f(26.8f, -10.0f);
	glVertex2f(26.8f, -20.0f);
	glVertex2f(27.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(31.0f, 110.0f);
	glVertex2f(30.8f, 110.0f);
	glVertex2f(30.8f, 100.0f);
	glVertex2f(31.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(31.0f, 70.0f);
	glVertex2f(30.8f, 70.0f);
	glVertex2f(30.8f, 60.0f);
	glVertex2f(31.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(31.0f, 30.0f);
	glVertex2f(30.8f, 30.0f);
	glVertex2f(30.8f, 20.0f);
	glVertex2f(31.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(31.0f, -10.0f);
	glVertex2f(30.8f, -10.0f);
	glVertex2f(30.8f, -20.0f);
	glVertex2f(31.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(35.0f, 110.0f);
	glVertex2f(34.8f, 110.0f);
	glVertex2f(34.8f, 100.0f);
	glVertex2f(35.0f, 100.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(35.0f, 70.0f);
	glVertex2f(34.8f, 70.0f);
	glVertex2f(34.8f, 60.0f);
	glVertex2f(35.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(35.0f, 30.0f);
	glVertex2f(34.8f, 30.0f);
	glVertex2f(34.8f, 20.0f);
	glVertex2f(35.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(35.0f, -10.0f);
	glVertex2f(34.8f, -10.0f);
	glVertex2f(34.8f, -20.0f);
	glVertex2f(35.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(39.0f, 110.0f);
	glVertex2f(38.8f, 110.0f);
	glVertex2f(38.8f, 100.0f);
	glVertex2f(39.0f, 100.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(39.0f, 70.0f);
	glVertex2f(38.8f, 70.0f);
	glVertex2f(38.8f, 60.0f);
	glVertex2f(39.0f, 60.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(39.0f, 30.0f);
	glVertex2f(38.8f, 30.0f);
	glVertex2f(38.8f, 20.0f);
	glVertex2f(39.0f, 20.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(39.0f, -10.0f);
	glVertex2f(38.8f, -10.0f);
	glVertex2f(38.8f, -20.0f);
	glVertex2f(39.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(43.0f, 110.0f);
	glVertex2f(42.8f, 110.0f);
	glVertex2f(42.8f, 100.0f);
	glVertex2f(43.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(43.0f, 70.0f);
	glVertex2f(42.8f, 70.0f);
	glVertex2f(42.8f, 60.0f);
	glVertex2f(43.0f, 60.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(43.0f, 30.0f);
	glVertex2f(42.8f, 30.0f);
	glVertex2f(42.8f, 20.0f);
	glVertex2f(43.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(43.0f, -10.0f);
	glVertex2f(42.8f, -10.0f);
	glVertex2f(42.8f, -20.0f);
	glVertex2f(43.0f, -20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(47.0f, 110.0f);
	glVertex2f(46.8f, 110.0f);
	glVertex2f(46.8f, 100.0f);
	glVertex2f(47.0f, 100.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(47.0f, 70.0f);
	glVertex2f(46.8f, 70.0f);
	glVertex2f(46.8f, 60.0f);
	glVertex2f(47.0f, 60.0f);
           glEnd();
           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(47.0f, 30.0f);
	glVertex2f(46.8f, 30.0f);
	glVertex2f(46.8f, 20.0f);
	glVertex2f(47.0f, 20.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(47.0f, -10.0f);
	glVertex2f(46.8f, -10.0f);
	glVertex2f(46.8f, -20.0f);
	glVertex2f(47.0f, -20.0f);
           glEnd();


            glutPostRedisplay();


        }

   void star(){

        glPushMatrix();
        glTranslated(-44,100,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

     glPushMatrix();
        glTranslated(-39,95,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

     glPushMatrix();
        glTranslated(-30,91,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

     glPushMatrix();
        glTranslated(-23,80,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

     glPushMatrix();
        glTranslated(-17,67,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();


 glPushMatrix();
        glTranslated(-43,90,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();


    glPushMatrix();
        glTranslated(-5,65,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(5,55,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-20,100,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,90,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(17,75,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(25,85,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(40,105,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(32,88,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(40,60,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(42,30,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();


    glPushMatrix();
        glTranslated(35,40,0);
        glScaled(0.5,1.5,0);
        glColor3ub(224,224,224);
        circle(.4,.4);
    glPopMatrix();



   }

void Boat(){

    txB=txB-0.07;
         if(txB<-31){
            txB=20;
         }


    glBegin(GL_QUADS);

       glColor3ub(0, 0, 0);

	glVertex2f(30.0f, -15.0f);
    glVertex2f(33.0f,-20.0f);
	glVertex2f(43.0f, -20.0f);
	glVertex2f(45.0f, -15.0f);

glEnd();

 glBegin(GL_QUADS);

       glColor3ub(153, 153, 0);

	glVertex2f(33.0f, -15.0f);
    glVertex2f(33.0f,-10.0f);
	glVertex2f(43.0f, -10.0f);
	glVertex2f(43.0f, -15.0f);


glEnd();

glBegin(GL_POLYGON);

       glColor3ub(255, 128, 0);

	glVertex2f(35.0f, -10.0f);
    glVertex2f(41.0f,7.0f);
	glVertex2f(41.0f, -10.0f);


glEnd();


glutPostRedisplay();


}



void BoatN(){
    glPushMatrix();
        glTranslated(-25,25,0);
        //glScaled(0.5,1.5,0);
        glColor3f(1,0.843,0);
        Boat();
    glPopMatrix();
}





void cloudLeft(){
    cloudleftx=cloudleftx-0.05;
    if(cloudleftx<-50){
        cloudleftx=50;
    }



    glPushMatrix();
        glTranslated(-3.5+cloudleftx,8.5,3);
        glScaled(1,1,1);
        glColor3f(1.0f,1.0f,1.0f);


        glPushMatrix();
            glTranslated(1.5,90,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4,90.5,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4.5,89.7,0),
            circle(2.5,2.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,89,0),
            circle(1.5,2.5);
        glPopMatrix();
    glPopMatrix();

    glutPostRedisplay();


}




void cloudRight(){

    cloudrightx=cloudrightx-0.02;
    if(cloudrightx<-50){
        cloudrightx=50;
    }


    glPushMatrix();
        glTranslated(-3.5+cloudrightx,2.5,-5);
        glScaled(1,1,1);
        glColor3f(1.0f,1.0f,1.0f);


        glPushMatrix();
            glTranslated(1.5,84,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4,84.5,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4.5,83.7,0),
            circle(2.5,2.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,83,0),
            circle(1.5,2.5);
        glPopMatrix();
    glPopMatrix();

    glutPostRedisplay();

}



void cloudMiddle(){
    cloudmiddlex=cloudmiddlex-0.04;
    if(cloudmiddlex<-50){
        cloudmiddlex=50;
            }



    glPushMatrix();
    glTranslated(-3.5+cloudmiddlex,9,1);
    glScaled(1,1,1);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,83.5,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,86.5,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,86.5,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5,84,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,83,1),
    circle(1.5,2.5);
    glPopMatrix();
glPopMatrix();

glutPostRedisplay();


}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(202, 235, 245);
	glVertex2f(-50.0f, 110.0f);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(197, 233, 238);
    glVertex2f(50.0f, 20.0f);
	glVertex2f(-50.0f, 20.0f);
    glEnd();
}


void skyN()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 102);
	glVertex2f(-50.0f, 110.0f);
	 glColor3ub(51, 51, 255);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(153, 204, 255);
    glVertex2f(50.0f, 20.0f);
     glColor3ub(204, 229, 255);
	glVertex2f(-50.0f, 20.0f);
    glEnd();
}
void skyR(){

     glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
	glVertex2f(-50.0f, 110.0f);
	 //glColor3ub(51, 51, 255);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(160, 160, 160);
    glVertex2f(50.0f, 20.0f);
     //glColor3ub(204, 229, 255);
	glVertex2f(-50.0f, 20.0f);
    glEnd();

}


void DayDisplay(void)
{
    sky();
    sun();
    cloudLeft();
    cloudRight();
    cloudMiddle();
    Hill();
    Ground();
    Tree();
    House1();
    House2();
    Path();
    River();
    glPushMatrix(); // Draws The boat
    glTranslatef(txB,tyB,0);
     Boat();
    glPopMatrix();
    Grass();
    glFlush();
}

void NightDisplay(){

     skyN();
     star();
    moon();
    cloudLeft();
    cloudRight();
    cloudMiddle();
     Hill();
     Ground();
     Tree();
     House1();
     House2();
     Path();
      River();
      BoatN();
      Grass();

     glFlush();

}

void RainDisplay(){

    skyR();
    //sun();
    cloudLeft();
    cloudRight();
    cloudMiddle();
     Hill();
     Ground();
     Tree();
     House1();
     House2();
     Path();
      RiverR();
     glPushMatrix(); // Draws The boat
    glTranslatef(txB,tyB,0);
     Boat();
    glPopMatrix();
      Grass();
       glPushMatrix(); // Draws The Rain
    glTranslatef(txR,tyR,0);
     Rain();
     glPopMatrix();
     glFlush();

}

void Display()
{
    screen();
    introscreen();
    glFlush();
    glutPostRedisplay();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GLUT_SINGLE| GLUT_RGB);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'd':

			glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	     glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Day scenerio");
      init();
	glutKeyboardFunc(my_keyboard);

	glutDisplayFunc(DayDisplay);
	PlaySound("salamisound-1755562-birds-chirping-songbirds-in.wav",NULL,SND_FILENAME|SND_ASYNC);
	glutPostRedisplay();
			break;

		case 'n':
			glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	     glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Night scenerio");
    init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(NightDisplay);
     PlaySound("Night-sounds.wav",NULL,SND_FILENAME|SND_ASYNC);
	glutPostRedisplay();
			break;

			case 'r':
			glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	     glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Rain scenerio");
    init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(RainDisplay);
    PlaySound("rain-02.wav",NULL,SND_FILENAME|SND_ASYNC);
	glutPostRedisplay();
			break;



	  default:
			break;
	}
}

int main(int arg, char **argv)
{
    glutInit(&arg, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("City View");
	init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}

