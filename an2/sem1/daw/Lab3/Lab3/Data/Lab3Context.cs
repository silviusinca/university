using Lab3.Models;
using Lab3.Models.OneToMany;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Lab3.Data
{
    public class Lab3Context : DbContext
    {
        public DbSet<Student> Students { get; set; }

        public DbSet<Model1> Models1 { get; set; }
        public DbSet<Model2> Models2 { get; set;  }

        public Lab3Context(DbContextOptions<Lab3Context> options) : base(options)
        {

        }

        protected override void OnModelCreating(ModelBuilder builder)
        {
            builder.Entity<Model1>().HasMany(m1 => m1.Models2).WithOne(m2 => m2.Model1);

            builder.Entity<Model2>

            base.OnModelCreating(builder);
        }

    }
}
