using Lab3.Models.Base;

namespace Lab3.Models
{
    public class Student : BaseEntity
    {
        public string FirstName { get; set; }
        public string LastName { get; set; } 
        public string Age { get; set; }
        public string? Email { get; set; }
    }
}
