#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  
    if(checkPassword(password) == true)
        m_passwords.insert(std::pair<std::string,Usuario>(url, Usuario(login, password)));
  
}

void GooglePassword::remove(const std::string& url) {

  std::map<std::string, Usuario>::const_iterator it;

    if(m_passwords.find(url) == m_passwords.end())
        return;
    else{
        it = m_passwords.find(url);

        m_passwords.erase(it);
    }   
    
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {

  if(m_passwords.find(url) == m_passwords.end())
        return;

  if(m_passwords.find(url)->second.getPassword() == old_password)
  {
      if(checkPassword(new_password) == true)
        {
        std::map<std::string, Usuario>::const_iterator it;

        m_passwords.find(url)->second.setPassword(new_password);
        m_passwords.find(url)->second.setLogin(login);
        
        }
  }else
    return;

}

void GooglePassword::printPasswords() {

  std::cout << m_passwords.size() << "\n";

  for (std::map<std::string, Usuario>::const_iterator it = m_passwords.begin(); it != m_passwords.end(); it++)
    {
        std::cout << it->first << ": " << it->second.getLogin() << " and " << it->second.getPassword() << "\n" ;
    }
}

bool GooglePassword::checkPassword(const std::string& password) const {
 int aux = 0;
 std::string str ("123456");

  if(password.find(str) != std::string::npos)
        aux++;

  if(password.size() > 50 || password.size() < 6)  
    aux++;

  for(std::string::const_iterator it = password.begin(); it < password.end(); it++)
     {
         if(*it == ' ')
         {
            aux++;
            break;
         }
      }
  
  if(aux > 0)
    return false;
  else
    return true;
}