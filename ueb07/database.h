#ifndef DATABASE_H
#define DATABASE_H

void saveAppointment(FILE *Datei, sAppointment *Save);

int saveCalendar();

int loadCalendar();

int loadAppointment(FILE *Datei, sAppointment *Load);

#endif