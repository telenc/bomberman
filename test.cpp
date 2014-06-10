if (!this->texture.load("./images/bomber.tga"))
  {
    std::cerr << "Impossible de charger la texture bomber.tga" << std::endl;
    return false;
  }

this->geometry.setColor(glm::vec4(1, 1, 1, 1));

this->geometry.pushVertex(glm::vec3(0, 0, 0));
this->geometry.pushVertex(glm::vec3(this->texture.getWidth(), 0, 0));
this->geometry.pushVertex(glm::vec3(this->texture.getWidth(), this->texture.getHeight(), 0));
this->geometry.pushVertex(glm::vec3(0, this->texture.getHeight(), 0));

this->geometry.pushUv(glm::vec2(0.0f, 1.0f));
this->geometry.pushUv(glm::vec2(1.0f, 1.0f));
this->geometry.pushUv(glm::vec2(1.0f, 0.0f));
this->geometry.pushUv(glm::vec2(0.0f, 0.0f));

this->geometry.build();




this->texture.bind();
this->geometry.draw(this->shader, glm::mat4(1), GL_QUADS);
