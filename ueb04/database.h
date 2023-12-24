#ifndef DATABASE_H
#define DATABASE_H

int saveAppointment(FILE *Datei, int selectAppointment);


int saveCalendar();

int loadCalendar();

int loadAppointment();

#endif