#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
//#include<math.h>
#include <glut.h>
// co ordinates of eight packets
static double x = 0, y = 0, z = 0, i1 = 0;
// p[8] is used to generate 8 different packets, 4 for each user. usind the keys 1-8

static bool p[8] = { false }, u[8] = { false };
//t1=false,sh1=false,sm1=false;
//static bool tt2=false,h2=false,sh2=false,sm2=false;
void* font;
void* currentfont;
void setFont(void* font)
{
    currentfont = font;
}
void drawstring(float x, float y, float z, char* string)
{
    char* c;
    glRasterPos3f(x, y, z);
    for (c = string;*c != '\0';c++)

    {
        glColor3f(0.0, 1.0, 1.0);
        glutBitmapCharacter(currentfont, *c);
    }
}
void
stroke_output(GLfloat x, GLfloat y, char* format, ...)
{
    va_list args;
    char buffer[200], * p;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    glPushMatrix();
    glTranslatef(-2.5, y, 0);
    glScaled(0.003, 0.005, 0.005);
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}
void server()

{
    glPushMatrix();
    glScaled(0.8, 2.0, 0.8);
    glTranslatef(-0.5, 0, -15);
    glColor3f(0, 1.5, 1.5);
    glutSolidCube(1);
    glPushMatrix();
    glScaled(0.5, .1, 1.0);
    glTranslatef(.0, 3.5, 0.01);
    glColor3f(0.3, 0.3, 0.3);
    glutSolidCube(1.5);
    glPopMatrix();
    glPushMatrix();
    glScaled(0.35, .05, 1.0);
    glTranslatef(0.0, 1, 0.1);
    glColor3f(0, 0, 0.3);
    glutSolidCube(1.1);
    glPopMatrix();
    glPushMatrix();
    glScaled(2.2, .1, 1.0);

    glTranslatef(0, -1, 0.3);
    glColor3f(0, 0, 1.3);
    glutSolidCube(0.5);
    glPopMatrix();
    glPushMatrix();
    glScaled(2.2, .1, 1.0);
    glTranslatef(0, -2, 0.3);
    glColor3f(0, 0, 1.3);
    glutSolidCube(0.5);
    glPopMatrix();
    glPushMatrix();
    glScaled(2.2, .1, 1.0);
    glTranslatef(0, -3, 0.3);
    glColor3f(0, 0, 1.3);
    glutSolidCube(0.5);
    glPopMatrix();
    glPopMatrix();
}
void plane()

{
    glScaled(0.2, 0.1, 0.3);
    if (p[0] || p[4])
        glColor3f(1, 1, 0);
    if (p[1] || p[5])
        glColor3f(0, 1, 0);
    if (p[2] || p[6])
        glColor3f(1, 0, 0);
    if (p[3] || p[7])
        glColor3f(0, 1, 1);
    glutSolidSphere(1.0, 40, 40);
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0, 0, 0);
    glScaled(3, 0.3, 0.01);
    glutSolidSphere(1.0, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0, 2, 0.8);
    glScaled(0.2, 3, 0.01);
    glutSolidSphere(1.0, 40, 40);
    glPopMatrix();
}
void wall() {
    glPushMatrix();
    glTranslatef(-1.5, -0.05, -6);
    glColor3f(1, 1, 1);
    glScaled(4.7, 3.05, 0.2);
    glutSolidCube(1);
    glPopMatrix();
    for (float y = -5;y <= 5;y += 0.65) {
        for (float x = -5.3; x <= 1;x += 0.57) {
            glPushMatrix();
            glColor3f(0.4, 0.4, 0.4);
            glScaled(.7, 0.3, 0.5);

            glTranslatef(x, y, -12);
            glutSolidCube(0.5);
            glPopMatrix();
        }
    }
}
void user()
{
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 1.2, 1);
    //glScaled(0.3,0.35,0.01);
    glutSolidSphere(0.4, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 0, 1);
    glScaled(0.6, 1.7, 0.6);
    glutSolidSphere(0.6, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0.35, -0.1, 1);
    glScaled(0.2, 2, 0.2);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.2, 0.4, 40, 40);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-0.3, -0.1, 1.2);
    glScaled(0.2, 2, 0.2);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.2, 0.4, 40, 40);
    glPopMatrix();
}
//PC Computers
void pc()
{
    glPushMatrix();
    glTranslatef(0, 0, 3);glScaled(.7, .7, 0);
    glColor3f(0, 1, 0);
    glutSolidCube(1);
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0, -0.65, 0);
    glScaled(1.1, 0.3, 0);
    glutSolidCube(1);
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(0, 0, 0);
    glScaled(0.6, 0.15, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 0, 3);
    glScaled(.7, .7, 0);

    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();
}
void port(float x1, float y1) {
    glPushMatrix();
    glTranslatef(x1, y1, -5.85);
    glScaled(0.4, 0.45, 0.01);
    glutSolidSphere(1.0, 40, 40);
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0, 0, 1);
    glScaled(1, 1, 0.01);
    glutSolidSphere(0.8, 40, 40);
    glPopMatrix();

    glPopMatrix();
}
void packet() {
    glPushMatrix();
    glColor3f(1, 0, 1);
    // Move packet to spring
    if (z <= 10) {
        z += 0.1;
        glTranslatef(-2, -2, 5 - z);
        plane();
    }
    // http packet
    if (p[0] && z >= 10 || p[4] && z >= 10) {
        //towards port 80
        if (z >= 10 && y <= 3)
        {
            x -= 0.01;
            y += 0.02;
            z += 0.01;
            glTranslatef(-2 + x, -2 + y, 5 - z);
            plane();
            //glutSolidCube(0.3);
        }
        else if
            //Allow or Block
            (p[0] && u[0] || p[4] && u[4])
        {
            if (z <= 17) {
                z += 0.1;
            }
            if (z >= 17)
            {
                z = 150;
            }glTranslatef(-2 + x, -2 + y, 5 - z);
            plane();
            //glutSolidCube(0.3);
        }
        else

        {
            i1 += 0.1;
            for (float x4 = 0;x4 <= 3;x4++)
            {
                glPushMatrix();
                glScalef(0.3, 0.3, 0.3);
                if (x4 == 0)
                    glTranslatef(-7.5 + i1, 12 + i1, -5.85);
                if (x4 == 1)
                    glTranslatef(-7.5 - i1, 12 + i1, -5.85);
                if (x4 == 2)
                    glTranslatef(-7.5 + i1, 12 - i1, -5.85);
                if (x4 == 3)
                    glTranslatef(-7.5 - i1, 12 - i1, -5.85);
                //plane();
                glutSolidCube(0.3);
                glPopMatrix();
            }

        }
    }
    // Telnet Packets
    if (p[1] && z >= 10 || p[5] && z >= 10) {
        //towards port 23
        if (z >= 10 && y <= 3)
        {
            x -= 0.002;
            y += 0.01;
            z += 0.005;
            glTranslatef(-2 + x, -2 + y, 5 - z);
            plane();
            //glutSolidCube(0.3);
        }
        else if
            //Allow or Block
            (p[1] && u[1] || p[5] && u[5])
        {
            if (z <= 17) {
                z += 0.1;
            }

            if (z >= 17)
            {
                z = 150;
            }glTranslatef(-2 + x, -2 + y, 5 - z);
            plane();
        }
        else
        {
            i1 += 0.1;
            for (float x4 = 0;x4 <= 3;x4++)
            {
                glPushMatrix();
                glScalef(0.3, 0.3, 0.3);
                if (x4 == 0)
                    glTranslatef(-5.6 + i1, 12 + i1, -5.85);
                if (x4 == 1)
                    glTranslatef(-5.6 + i1, 12 - i1, -5.85);
                if (x4 == 2)
                    glTranslatef(-5.6 - i1, 12 + i1, -5.85);
                if (x4 == 3)

                    glTranslatef(-5.6 - i1, 12 - i1, -5.85);
                glutSolidCube(0.3);
                glPopMatrix();
            }
        }
    }
    // SSH Packets
    if (p[2] && z >= 10 || p[6] && z >= 10) {
        //towards port 23
        if (z >= 10 && y <= 3)
        {
            x += 0.002;
            y += 0.01;
            z += 0.005;
            glTranslatef(-1.8 + x, -2 + y, 5 - z);
            plane();
        }
        else if
            //Allow or Block

            (p[2] && u[2] || p[6] && u[6])
        {
            if (z <= 17) {
                z += 0.1;
            }
            if (z >= 17)
            {
                z = 150;
            }glTranslatef(-1.8 + x, -2 + y, 5 - z);
            plane();
        }
        else
        {
            i1 += 0.1;
            for (float x4 = 0;x4 <= 3;x4++)
            {
                glPushMatrix();
                glScalef(0.3, 0.3, 0.3);
                if (x4 == 0)
                    glTranslatef(-3.6 + i1, 12 + i1, -5.85);
                if (x4 == 1)
                    glTranslatef(-3.6 + i1, 12 - i1, -5.85);

                if (x4 == 2)
                    glTranslatef(-3.6 - i1, 12 + i1, -5.85);
                if (x4 == 3)
                    glTranslatef(-3.6 - i1, 12 - i1, -5.85);
                glutSolidCube(0.3);
                glPopMatrix();
            }
        }
    }
    // SMTP Packets
    if (p[3] && z >= 10 || p[7] && z >= 10) {
        //towards port 23
        if (z >= 10 && y <= 2)
        {
            x += 0.0081;
            y += 0.01;
            z += 0.005;
            glTranslatef(-2 + x, -2 + y, 5 - z);

            plane();
        }
        else if
            //Allow or Block
            (p[3] && u[3] || p[7] && u[7])
        {
            if (z <= 17) {
                z += 0.1;
            }
            if (z >= 17)
            {
                z = 150;
            }
            glTranslatef(-2 + x, -2 + y, 5 - z);
            plane();
        }
        else
        {
            i1 += 0.1;
            for (float x4 = 0;x4 <= 3;x4++)
            {
                glPushMatrix();

                glScalef(0.3, 0.3, 0.3);
                if (x4 == 0)
                    glTranslatef(-1.5 + i1, 11 + i1, -5.85);
                if (x4 == 1)
                    glTranslatef(-1.5 + i1, 11 - i1, -5.85);
                if (x4 == 2)
                    glTranslatef(-1.5 - i1, 11 + i1, -5.85);
                if (x4 == 3)
                    glTranslatef(-1.5 - i1, 11 - i1, -5.85);
                glutSolidCube(0.3);
                glPopMatrix();
            }
        }
    }
    glPopMatrix();
}