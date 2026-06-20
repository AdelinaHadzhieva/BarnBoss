#include "profileInfoCommand.h"
ProfileInfoCommand::ProfileInfoCommand(const User* user):user(user){}
    void ProfileInfoCommand::execute(){
        user->profileInfo();
    }
