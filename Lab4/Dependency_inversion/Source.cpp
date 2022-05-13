#include <iostream>
#include"HEADER.h"

// Single Responsibility 
// Dependency Inversion

int main()
{
	Photo_file* f_photo = new Photo_file();
	Video_file* f_video = new Video_file();
	Sound_file* f_sound = new Sound_file();

	Flash_disk* flash = new Flash_disk();
	Hard_disk* hard = new Hard_disk();

	Save_file* save1 = new Save_file();

	save1->saving(f_photo, flash);
	save1->saving(f_video, flash);
	save1->saving(f_sound, flash);
	save1->saving(f_photo, hard);
	save1->saving(f_video, hard);
	save1->saving(f_sound, hard);

	return 0;
}

