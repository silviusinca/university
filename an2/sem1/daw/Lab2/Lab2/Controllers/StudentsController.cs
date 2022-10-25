using Lab2.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.JsonPatch;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using System.Net.NetworkInformation;

namespace Lab2.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class StudentsController : ControllerBase
    {

        public static List<Student> students = new List<Student>
        {
            new Student { Id = 1, Name = "Silviu", Age = 20},
            new Student { Id = 2, Name = "Maria", Age = 30},
            new Student { Id = 3, Name = "Vlad", Age = 31},
            new Student { Id = 4, Name = "Florin", Age = 25},
            new Student { Id = 5, Name = "Andreea", Age = 21},
            new Student { Id = 6, Name = "Andreea", Age = 35},
            new Student { Id = 7, Name = "Andreea", Age = 24}
        };

        public static Dictionary<int, Student> studentDictionary = new Dictionary<int, Student>
        {
            {1, new Student { Id = 1, Name = "Silviu", Age = 20} },
            {2, new Student { Id = 2, Name = "Maria", Age = 30} }
        };

        // endpoint

        // gets
        [HttpGet]
        public List<Student> Get()
        {
            return students;
        }

        [HttpGet("byId")]
        public Student GetById(int id)
        {
            return students.FirstOrDefault(x => x.Id.Equals(id));
        }

        [HttpGet("byId/{id}")]
        public Student GetByIdInEndpoint(int id)
        {
            return students.FirstOrDefault(s => s.Id.Equals(id));
        }

        [HttpGet("filter/{name}/{age}")]
        public List<Student> GetWithFilters(string name, int age)
        {
            return students.Where(stud => stud.Name.ToLower().Equals(name.ToLower()) && stud.Age > age).ToList();
        }

        [HttpGet("fromRouteWithId/{id}")]
        public Student GetByIdWithFromRoute([FromRoute] int id)
        {
            Student student = students.FirstOrDefault(x => x.Id.Equals(id));
            return student;
        }

        [HttpGet("fromHeader")]
        public Student GetByIdWithFromHeader([FromHeader] int id)
        {
            return students.FirstOrDefault(s => s.Id.Equals(id));
        }
        
        [HttpGet("fromQuery")]
        public Student GetByIdWithFromQuery([FromQuery] int id)
        {
            return students.FirstOrDefault(s => s.Id.Equals(id));
        }

        // 200
        [HttpGet("StatusCodeOk")]
        public IActionResult StatusCodeOk()
        {
            return Ok("It's ok");
        }

        // 204
        [HttpGet("StatusCodeNoContent")]
        public IActionResult StatusCodeNoContent()
        {
            return NoContent();
        }

        // 404
        [HttpGet("StatusCodeNotFound")]
        public IActionResult StatusCodeNotFound()
        {
            return NotFound();
        }

        // 403
        [HttpGet("StatusCodeForbid")]
        public IActionResult StatusCodeForbid()
        {
            return Forbid();
        }

        // 400
        [HttpGet("StatusCodeBadRequest")]
        public IActionResult StatusCodeBadRequest()
        {
            return BadRequest();
        }

        // create
        [HttpPost("post")]
        public IActionResult Add(Student student)
        {
            students.Add(student);
            return Ok(students);
        }

        [HttpPost("postInDictionary")]
        public IActionResult AddInDictionary(Student student) {
            studentDictionary.Add(student.Id, student);
            return Ok(studentDictionary);
        }

        [HttpPost("fromBody")] 
        public IActionResult AddWithFromBody([FromBody] Student student)
        {
            students.Add(student);
            return Ok(students);
        }
        [HttpPost("fromForm")] 
        public IActionResult AddWithFromForm([FromForm] Student student)
        {
            students.Add(student);
            return Ok(students);
        }


        // updates

        // full update
        [HttpPost("update")]
        public IActionResult Update([FromBody] Student student)
        {
            var studentIndex = students.FindIndex((Student x) => x.Id == student.Id);
            students[studentIndex] = student;

            return Ok(students);
        }

        // metoda async 
        [HttpPost("updateAsync")]
        public async Task<IActionResult> UpdateAsync([FromBody] Student student)
        {
            var studentIndex = students.FindIndex((Student x) => x.Id == student.Id);
         
            // await
            students[studentIndex] = student;

            return Ok(students);
        }


        // update partial
        [HttpPatch("{id:int}")]
        public IActionResult Patch([FromRoute] int id, [FromBody] JsonPatchDocument<Student> student)
        {
            if (student != null)
            {
                var studentToUpdate = students.FirstOrDefault(x => x.Id == id);
                student.ApplyTo(studentToUpdate);

                if (!ModelState.IsValid)
                {
                    return BadRequest();
                }

                return Ok(students);
            }

            return BadRequest();
        }

        [HttpDelete]
        public IActionResult Delete(int id)
        {
            students.RemoveAt(students.FindIndex(x => x.Id == id));
            return Ok(students);
        }

    }
}
