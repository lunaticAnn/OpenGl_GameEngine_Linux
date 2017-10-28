#include "LineRenderer.h"
using namespace Rendering;
using namespace Models;

LineRenderer::LineRenderer(const glm::vec3& st, 
                             const glm::vec3& e,
                             const float& w,
                            //where this render face to
                             const glm::vec3& f = glm::vec3(0.0,1.0,0.0),
                             const glm::vec3& t = glm::vec3(0.0), 
                             const glm::vec3& sc = glm::vec3(1.0), 
                             const glm::vec3& r = glm::vec3(0.0)){
    start = st;
    end = e;
    width = w;
    front = f;
    translation = t;
    scale = sc;
    rotation = r;

};

LineRenderer::~LineRenderer(){
}

void LineRenderer::Create(){
	GLuint vao;
	GLuint vbo;

	time(&timer);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	//vertices for the front face of the LineRenderer
    	


	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);

}

void LineRenderer::Update(){
	Model::Update();
}

void LineRenderer::Draw(const glm::mat4& projection_matrix,
	const glm::mat4& view_matrix){

	glUseProgram(program);
	glUniformMatrix4fv(glGetUniformLocation(program, "model_matrix"),1,
		false, &TransformMatrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1,
		false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
