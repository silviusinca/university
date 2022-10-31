using Lab3.Data;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Lab3.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class StudentController : ControllerBase
    {
        private readonly Lab3Context _lab3Context;

        [HttpGet]
        public async Task<IActionResult> Get()
        {
            return Ok(await _lab3Context.Students.ToListAsync());
        }

        [HttpGet("studentById/{id}")]
        public async Task<IActionResult> GetStudentById([FromRoute] Guid Id)
        {
            // linq
            var studentById1 = _lab3Context.Students.FirstOrDefault(x => x.Id == Id);

            // sql syntax
            var studentById2 = from student in _lab3Context.Students
                               where student.Id == Id
                               select studentById1;

            return Ok(studentById1);
        }

        public StudentController(Lab3Context lab3Context)
        {
            _lab3Context = lab3Context;
        }
    }
}
